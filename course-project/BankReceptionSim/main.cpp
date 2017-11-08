/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 29, 2017
 * File: main.cpp
 * Purpose: Service Desk Simulation.
 *          Module 02 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "BankReception.h"
#include "TransactionType.h"
#include "Customer.h"
#include "Transaction.h"
#include "EventType.h"
#include "Event.h"

using namespace std;

// program name
const string APP_NAME = "Bank Reception Simulator";

// main menu options
const array<string, 3> MENU_OPTIONS = {
    "Simulate",
    "View Last Report",
    "Exit Program"
};

const int OPEN_TIME = 1; // open reception at time:10:00 (1)
const int CLOSE_TIME = 181; // close reception at time:13:00 (181)

/**
 * Print main menu options
 */
void printMenuOptions() {
    cout << endl << "---------------------------" << endl;
    cout << APP_NAME << endl;
    cout << "---------------------------" << endl;

    for (int i=0; i<MENU_OPTIONS.size(); i++) {
        cout << i+1 << ". " << MENU_OPTIONS[i] << endl;
    }

    cout << endl << "Select an option: ";
}

/**
 * Swaps 2 elements in an array.
 * @param data
 * @param i
 * @param j
 */
void swap(int* data, int i, int j) {
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

/**
 * Sorts the array using quick sort algorithm.
 * @param data
 * @param first
 * @param last
 * @param approach
 * @return
 */
void quickSort(int* data, int first, int last, int approach) {
    int i = first;
    int j = last;
    
    // get pivot
    int pivot = (first + last) / 2;

    while (i <= j) {

        while (data[i] < data[pivot]) {
            i++;
        }

        while (data[j] > data[pivot]) {
            j--;
        }

        if (i <= j) {
            swap(data, i, j);
            i++;
            j--;
        }
    }

    if (j > first) {
        // Sort the left half. 
        quickSort(data, first, j, approach);
    }

    if (i < last) {
        // Sort the right half. 
        quickSort(data, i, last, approach);
    }
}

/**
 * Returns random int between min and max
 * @param min
 * @param max
 * @return 
 */
int getRandomInt(int min, int max) {
    return min + (static_cast<int>(rand() % (max - min + 1)));
}

double getRandomDouble(int min, int max) {
    return min + (static_cast<double>(rand() % (max - min + 1)));
}

/**
 * Returns random transaction duration between 5 to 8 minutes
 * @return 
 */
double getRandomTransactionDuration() {
    return 5 + (static_cast<double>(rand() % (8 - 5 + 1)));
}

/**
 * Returns random transaction type in {open, close, deposit, withdraw}
 * @return 
 */
TransactionType getRandomTransactionType() {
    TransactionType p;

    int r = 1 + (static_cast<int>(rand() % (4 - 1 + 1)));
    
    switch (r) {
        case 1:
            p = TransactionType::open;
            break;
        case 2:
            p = TransactionType::close;
            break;
        case 3:
            p = TransactionType::deposit;
            break;
        case 4:
        default:
            p = TransactionType::withdraw;
            break;
    }

    return p;    
}

/**
 * Returns a random first name for customer
 * @return 
 */
string getRandomFirstName() {
    array<string, 9> names = {"Jon", "Sansa", "Khal", "Paul", "Tyrion", "Daenerys", "Arya", "Eddard", "Gregor"};

    return names[getRandomInt(0, 8)];
}

/**
 * Returns a random Last Name for customer
 * @return 
 */
string getRandomLastName() {
    array<string, 9> names = {"Snow", "Smith", "Black", "Lannister", "Stark", "Baelish", "Targaryen", "Baratheon", "Drogo"};

    return names[getRandomInt(0, 8)];
}

/**
 * Print reports
 * @param reception
 */
void printStatistics(BankReception* reception) {
    cout << endl << endl << "Statistics for Last Simulation" << endl;
    cout << "--------------------------------------" << endl;
    
    reception->printReport();
    
    cout << endl << endl;
}

/**
 * Generate and dispatch events based on the simulation state and the currentTime.
 * @param reception
 * @param currentTime
 */
void simulate(BankReception* reception, int& currentTime, bool debug) {
    // declare some variables
    Customer* cust;
    Transaction* tr;
    bool dispatch = false;

    if (debug)
        cout << "[" << currentTime << "] events:" << reception->getEvents().size()
                << ", waiting customers:" << reception->getWaitingCustomers().size()
                << ", served customers:" << reception->getCustomers().size()
                << ", tellers:" << reception->getTellers().size()
                << endl;
    
    // dispatch any existing event
    if (!reception->getEvents().empty()) {
        // get next event
        Event* e = reception->getEvents().front();

        switch (e->getType()) {
            case EventType::BANK_OPEN:
                if (debug)
                    cout << "< opening" << endl;
                reception->setOpen();
                dispatch = true;
                break;

            case EventType::BANK_CLOSE:
                if (debug)
                    cout << "< closing" << endl;
                reception->setClose();
                dispatch = true;
                break;

            case EventType::CUSTOMER_ENTER:
                if (debug)
                    cout << "< adding customer" << endl;

                // generate test transaction
                tr = new Transaction(getRandomTransactionType());
                tr->setDuration(getRandomTransactionDuration());
                tr->setAmount(getRandomDouble(1, 100));

                // generate a test customer
                cust = new Customer(getRandomInt(100, 900), getRandomFirstName(), getRandomLastName());
                cust->setEnterAt(currentTime);
                cust->setTransaction(tr); // add transaction to customer

                // add customer to bank
                if (reception->addCustomer(cust)) {
                    // add transaction to bank
                    reception->addTransaction(tr);
                }
                dispatch = true;

                break;

            case EventType::CUSTOMER_SERVE:
                if (debug)
                    cout << "< serving customer: ";
                
                if (reception->serveNextCustomer(currentTime)) {
                    dispatch = true;
                    if (debug)
                        cout << "done!" << endl;
                } else {
                    if (debug)
                        cout << "no free desk. Waiting." << endl;
                }
                
                break;

            case EventType::CUSTOMER_LEAVE:
                if (debug)
                    cout << "< leaving customer" << endl;
                dispatch = true;
                break;

            case EventType::TELLER_ADD:
                if (debug)
                    cout << "< adding teller" << endl;
                if (reception->addTeller()) {
                    dispatch = true;
                }

                break;
                

            case EventType::TELLER_REMOVE:
                if (debug)
                    cout << "< removing teller" << endl;
                reception->removeTeller();
                dispatch = true;
                break;
            
        }

        if (dispatch) {
            e->dispatch(currentTime);

            // remove event from the queue
            reception->removeEvent();
        }

    }

    // time to open bank
    if (currentTime >= OPEN_TIME && currentTime < CLOSE_TIME && !reception->isOpen()) {
        if (debug)
            cout << "+ open" << endl;
        reception->addEvent(new Event(EventType::BANK_OPEN, currentTime));
    }

    // time to close bank
    if (currentTime >= CLOSE_TIME && reception->isOpen()) {
        if (debug)
            cout << "+ close" << endl;
        reception->addEvent(new Event(EventType::BANK_CLOSE, currentTime));
    }

    // add 2nd teller if more than 4 customers are active and only 1 teller is active
    if (reception->getWaitingCustomers().size() >= 4 && reception->getTellers().size() == 1) {
        if (debug)
            cout << "+ add teller 2" << endl;
        reception->addEvent(new Event(EventType::TELLER_ADD, currentTime));
    }

    // add 3rd teller if more than 8 customers are waiting and only 2 tellers are active
    if (reception->getWaitingCustomers().size() >= 8 && reception->getTellers().size() == 2) {
        if (debug)
            cout << "+ add teller 3" << endl;
        reception->addEvent(new Event(EventType::TELLER_ADD, currentTime));
    }
    
    // remove 3rd teller when less than 8 customers are waiting and 3 tellers are active
    if (reception->getWaitingCustomers().size() < 8 && reception->getTellers().size() == 3) {
        if (debug)
            cout << "+ remove teller 3" << endl;
        reception->addEvent(new Event(EventType::TELLER_REMOVE, currentTime));
    }

    // remove 2nd teller when less than 4 customers are waiting and 2 tellers are active
    if (reception->getWaitingCustomers().size() < 4 && reception->getTellers().size() == 2) {
        if (debug)
            cout << "+ remove teller 2" << endl;
        reception->addEvent(new Event(EventType::TELLER_REMOVE, currentTime));
    }
    
    // customer enters? 60% chance a customer will enter
    if (getRandomInt(1, 10) >= 6 && reception->isOpen()) {
        if (debug)
            cout << "+ add customer" << endl;
        // the chance that a customer will enter the bank must be at least 60%
        reception->addEvent(new Event(EventType::CUSTOMER_ENTER, currentTime));
    }
    
    // if any customer is waiting, a teller must serve it
    if (reception->getWaitingCustomers().size() > 0) {
        if (debug)
            cout << "+ serve customer"<< endl;
        reception->addEvent(new Event(EventType::CUSTOMER_SERVE, currentTime));
    }

    // check if a customer transaction is complete
    if (reception->getCustomers().size() > 0) {
        if (reception->endServices(currentTime) > 0) {
            if (debug)
                cout << "+ leave customer"<< endl;
            reception->addEvent(new Event(EventType::CUSTOMER_LEAVE, currentTime));
        }
    }
    
}

/**
 * Starts a simulation.
 * Simulation will end when there are no more events to dispatch and it's not yet
 * time to close. Increase time by 1 minute on each iteration.
 * is beyond the Bank closing time
 * @param reception
 * @param currentTime
 */
void startSimulation(BankReception* reception, int& currentTime) {
    // while it's working time or there are still events queued
//    while (currentTime <= CLOSE_TIME || reception->getEvents().size() > 0) {
    while (currentTime <= CLOSE_TIME) {
        simulate(reception, currentTime, true);
        currentTime++;
    }
    
}

/**
 * main program function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    // declare some variables
    bool exitApp = false;
    int choice = 0;
    BankReception* reception; // initialize the bank reception
    int currentTime = 0; // start time is 0

    // main loop: repeat until user wants to exit the program
    while (!exitApp) {
        // print menu options
        printMenuOptions();
        
        // get user selection
        cin >> choice;

        switch (choice) {
            case 1:
                // start a new simulation at time 0
                currentTime = 0;
                cout << endl << "Simulation Started. Current time is: " << currentTime << endl;

                reception = new BankReception();
                
                // start simulation
                startSimulation(reception, currentTime);

                cout << endl << "Simulation Complete. Current time is: " << currentTime << endl;

                // print statistics (end of day)
                printStatistics(reception);

                break;

            case 2:
                // print the stats for the last simulation run
                printStatistics(reception);
                break;

            case 3:
                // end program
                exitApp = true;
                break;

            default:
                cout << endl << "Incorrect choice. Please try again." << endl;
        } // switch

    } // while
    
    cout << endl << "Bye!" << endl;
    
    return 0;
}
