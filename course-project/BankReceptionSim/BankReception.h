#ifndef BANKRECEPTION_H
#define BANKRECEPTION_H

#include <vector>
#include "Transaction.h"
#include "Teller.h"
#include "Customer.h"

using namespace std;

class BankReception {
public:
    BankReception();
    BankReception(const BankReception& orig);
    virtual ~BankReception();

    vector<Teller*> getTellers();
    vector<Customer*> getCustomers();
    vector<Transaction*> getTransactions();

    bool isOpen();
    void setOpen();
    void setClose();
    bool activateTeller();
    bool deactivateTeller();
    bool addCustomer(Customer* _customer);
    bool addTransaction(Transaction* _transaction);

private:
    bool open; // open from 10am to 1pm
    vector<Teller*> tellers; // list of tellers
    vector<Customer*> customers; // list of customers
    vector<Transaction*> transactions; // list of customers

};

#endif /* BANKRECEPTION_H */

