
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Transaction.h"

using namespace std;

class Customer {
public:
    Customer();
    Customer(int _id, string _firstName, string _lastName);
    Customer(const Customer& orig);
    virtual ~Customer();
    
    int getId();
    string getLastName();
    string getFirstName();
    void setAccount(string _account);
    string getAccount();
    void setEnterAt(int _timestamp);
    void setServiceAt(int _timestamp);
    void setLeaveAt(int _timestamp);
    int getEnterAt();
    int getServiceAt();
    int getLeaveAt();
    int getWaitingTime();
    int getTotalServiceTime();
    void setTransaction(Transaction* t);
    Transaction* getTransaction();

private:
    int id;
    string firstName;
    string lastName;
    string account;
    int enterAt;
    int serviceAt;
    int leaveAt;
    Transaction* transaction;
    
};

#endif /* CUSTOMER_H */
