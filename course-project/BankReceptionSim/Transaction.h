
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
//#include "Customer.h"
#include "TransactionType.h"

using namespace std;

class Transaction {
public:
    Transaction(TransactionType _type);
//    Transaction(TransactionType _type, Customer* _customer);
    Transaction(const Transaction& orig);
    virtual ~Transaction();
    
    string getType();
//    Customer* getCustomer();
    int getDuration();
    void setDuration(int _duration);
    double getAmount();
    void setAmount(double _amount);

private:
    TransactionType type;
//    Customer* customer;
    int duration; // amount of time required to complete the transaction (minutes)
    double amount;    

};

#endif /* TRANSACTION_H */

