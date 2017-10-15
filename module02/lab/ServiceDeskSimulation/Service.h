#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Priority.h"
#include "Customer.h"

class Service {
public:
    Service(Priority _priority, double _duration);
    Service(const Service& orig);
    virtual ~Service();

    Priority getPriority();
    std::string getPriorityDescription();
    double getDuration();
    Customer* getCustomer();
    void setCustomer(Customer* _customer);

private:
    Priority priority;
    double duration;
    Customer* customer;

};

#endif /* SERVICE_H */
