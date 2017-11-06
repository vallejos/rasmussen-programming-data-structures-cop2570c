#ifndef BANKRECEPTION_H
#define BANKRECEPTION_H

#include <vector>
#include <queue>
#include "Transaction.h"
#include "Teller.h"
#include "Customer.h"
#include "EventType.h"
#include "Event.h"

using namespace std;

class BankReception {
public:
    BankReception();
    BankReception(const BankReception& orig);
    virtual ~BankReception();

    vector<Teller*> getTellers();
    vector<Customer*> getCustomers();
    vector<Transaction*> getTransactions();
    queue<Event*> getEvents();

    bool isOpen();
    void setOpen();
    void setClose();
    bool addTeller();
    bool removeTeller();
    bool addCustomer(Customer* _customer);
    bool addTransaction(Transaction* _transaction);
    void addEvent(Event* e);
    void removeEvent();
    void serveNextCustomer();

private:
    bool open; // open from 10am to 1pm
    vector<Teller*> tellers; // list of tellers
    vector<Customer*> customers; // list of customers
    vector<Transaction*> transactions; // list of customers
    queue<Event*> events; // queue of events

};

#endif /* BANKRECEPTION_H */

