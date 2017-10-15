#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
public:
    Customer();
    Customer(const Customer& orig);
    virtual ~Customer();

private:
    std::string name;

};

#endif /* CUSTOMER_H */
