
#include "BankReception.h"
#include "Teller.h"

BankReception::BankReception() {
    open = false; // bank is closed
    
    Teller* t1 = new Teller(1);
    t1->setActive(); // only 1 teller is active initially

    tellers.push_back(t1);
    tellers.push_back(new Teller(2));
    tellers.push_back(new Teller(3));
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

bool BankReception::activateTeller() {
    // get last active teller
    
    // set next teller active
    
    // return false if all tellers were active, true otherwise
}

bool BankReception::deactivateTeller() {
    // get last active teller
    
    // set teller inactive
    
    // return false if only teller 1 was active, true otherwise
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
