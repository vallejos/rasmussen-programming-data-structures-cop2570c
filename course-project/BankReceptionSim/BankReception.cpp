
#include "BankReception.h"
#include "Teller.h"

BankReception::BankReception() {
    open = false; // bank is closed
    
    Teller* t1 = new Teller(1);
    t1->setActive(); // only 1 teller is active initially

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
        t->setActive();

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

    customers.push_back(_customer);
    
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

void BankReception::serveNextCustomer() {
    if (!customers.empty()) {
        customers.pop_back();
    }

}