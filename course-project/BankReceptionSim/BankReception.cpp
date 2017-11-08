
#include <iostream>
#include <iomanip> // setw
#include "BankReception.h"
#include "Teller.h"

using namespace std;

BankReception::BankReception() {
    open = false; // bank is closed
    avgWaitingCustomers = 0;
    avgWaitingTime = 0;
    Teller* t1 = new Teller(1);

    tellers.push_back(t1);
}

BankReception::BankReception(const BankReception& orig) {
}

BankReception::~BankReception() {
}

/**
 * Closes reception
 * @return 
 */
void BankReception::setClose() {
    open = false;
}

/**
 * Opens reception
 * @return 
 */
void BankReception::setOpen() {
    open = true;
}

/**
 * Returns whether the reception is open or not
 * @return 
 */
bool BankReception::isOpen() {
    return open;
}

vector<Teller*> BankReception::getTellers() {
    return tellers;
}

vector<Customer*> BankReception::getWaitingCustomers() {
    return waitingCustomers;
}

vector<Customer*> BankReception::getCustomers() {
    return customers;
}

vector<Transaction*> BankReception::getTransactions() {
    return transactions;
}

queue<Event*> BankReception::getEvents() {
    return events;
}

bool BankReception::addTeller() {
    bool activated = false;
    int current = tellers.size();
    
    // no more than 3 tellers can be active
    if (current < 3) {
        Teller* t = new Teller(current++);

        tellers.push_back(t);
        activated = true;
    }
    
    return activated;
}

bool BankReception::removeTeller() {
    bool removed = false;
    int current = tellers.size();
    
    // at least 1 teller must be active
    if (current > 1) {
        tellers.pop_back();
        removed = true;
    }
    
    return removed;
}

bool BankReception::addCustomer(Customer* _customer) {
    if (!isOpen()) {
        return false;
    }

    waitingCustomers.push_back(_customer);
    
    return true;
}

bool BankReception::addTransaction(Transaction* _transaction) {
    if (!isOpen()) {
        return false;
    }

    transactions.push_back(_transaction);

    return true;
}

void BankReception::addEvent(Event* e) {
    events.push(e);
}

void BankReception::removeEvent() {
    events.pop();
}

Teller* BankReception::getAvailableTeller() {
    Teller* teller = NULL;
    Teller* t;

    // iterate through tellers to get first available teller (not busy)
    for (std::vector<Teller*>::iterator it = tellers.begin(); it != tellers.end(); ++it) {
        t = *(it);
        
        if (!t->isBusy()) {
            teller = t;
        }
    }
    
    return teller;
}

bool BankReception::serveNextCustomer(int _timestamp) {
    bool served = false;
    
    // if there are waiting customers
    if (!waitingCustomers.empty()) {

        Teller* teller = getAvailableTeller();
        
        // if there's a free desk
        if (teller != NULL) {
            cout << endl << "\t free teller at desk #" << teller->getDesk() << endl;
            // get next waiting customer
            Customer* c = waitingCustomers.back();
            waitingCustomers.pop_back();
            c->setServiceAt(_timestamp);

            cout << "\t customer id: " << c->getId() << endl;
            cout << "\t transaction: " << c->getTransaction()->getType() << endl;
            cout << "\t amount: " << c->getTransaction()->getAmount() << endl;
            cout << "\t time: " << c->getTransaction()->getDuration() << endl;
            
            // start teller service
            teller->startService(c->getTransaction());

            customers.push_back(c);
            served = true;
        } else {
            cout << "\t no free teller: " << endl;
        }

        // update average waiting customers
        avgWaitingCustomers = waitingCustomers.size();
    }

    return served;
}


int BankReception::endServices(int _timestamp) {
    int ended = 0;
    Customer* cust;
    Teller* t;

    if (!customers.empty()) {
        // iterate through customers
        for (std::vector<Customer*>::iterator it = customers.begin(); it != customers.end(); ++it) {
            cust = *(it);

            if (cust->getLeaveAt() == 0 && cust->getServiceAt()) {
                // customer leaves
                cust->setLeaveAt(_timestamp);
                ended++;
                
                // need to find the teller and free it
                t = tellers.back();
                t->endService();
            }
        }
    }

    return ended;
}

void BankReception::printReport() {
    Customer* c;
    int time=182;
    
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "Customers that came today" << endl;
    cout << "-------------------------" << endl;
    cout << setw(3) << "ID";
    cout << setw(12) << "Last Name";
    cout << setw(12) << "First Name";
    cout << setw(12) << "Transaction";
    cout << setw(10) << "Amount";
    cout << setw(12) << "Arrived At";
    cout << setw(10) << "Avg.Wait";
    cout << setw(20) << "Customers Waiting";
    cout << endl;
    for (std::vector<Customer*>::iterator it = customers.begin(); it != customers.end(); ++it) {
        c = *(it);
        cout << setw(3) << c->getId();
        cout << setw(12) << c->getLastName();
        cout << setw(12) << c->getFirstName();
        cout << setw(12) << c->getTransaction()->getType();
        cout << setw(10) << c->getTransaction()->getAmount();
        cout << setw(12) << c->getEnterAt();
        cout << setw(10) << c->getWaitingTime();
        cout << setw(20) << avgWaitingCustomers;
        cout << endl;
    }
    
}