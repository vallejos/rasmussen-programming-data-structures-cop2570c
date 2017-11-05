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

using namespace std;

// program name
const string APP_NAME = "Bank Reception Simulator";

// main menu options
const array<string, 4> MENU_OPTIONS = {
    "Simulate",
    "Open Bank",
    "Close Bank",
    "Exit Program"
};

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
 * main program function
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    // declare some variables
    bool exitApp = false;
    int choice = 0;
    BankReception* reception = new BankReception();
    double currentTime = 0;

    // generate a test customer
    Customer* c1 = new Customer(1, "Jon", "Snow");

    // generate test transaction
    Transaction* t1 = new Transaction(getRandomTransactionType(), c1);
    t1->setDuration(getRandomTransactionDuration());

    // main loop
    while (!exitApp) {
        // print menu options
        printMenuOptions();
        
        // get user selection
        cin >> choice;

        switch (choice) {
            case 1:
                cout << endl << "Coming soon..." << endl;

                // add customer to bank
                if (!reception->addCustomer(c1)) {
                    cout << endl << "Bank is closed" << endl;
                } else {
                    // add transaction to bank
                    if (!reception->addTransaction(t1)) {
                        cout << endl << "Bank is closed" << endl;
                    }
                }
                
                break;

            case 2:
                reception->setOpen();
                cout << endl << "Bank is now Open" << endl;
                break;

            case 3:
                reception->setClose();
                cout << endl << "Bank is now Closed" << endl;
                break;

            case 4:
                // end program
                exitApp = true;
                break;

            default:
                cout << endl << "Incorrect choice. Please try again." << endl;
        } // switch

    } // while
    
    return 0;
}
