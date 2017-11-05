
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using namespace std;

class Customer {
public:
    Customer();
    Customer(int _id, string _firstName, string _lastName);
    Customer(const Customer& orig);
    virtual ~Customer();

private:
    int id;
    string firstName;
    string lastName;

};

#endif /* CUSTOMER_H */
