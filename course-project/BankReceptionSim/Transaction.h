
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Customer.h"
#include "TransactionType.h"

class Transaction {
public:
    Transaction(TransactionType _type, Customer* _customer);
    Transaction(const Transaction& orig);
    virtual ~Transaction();
    
    TransactionType getType();
    Customer* getCustomer();
    double getDuration();
    void setDuration(double _duration);

private:
    TransactionType type;
    Customer* customer;
    double duration; // amount of time required to complete the transaction

};

#endif /* TRANSACTION_H */

