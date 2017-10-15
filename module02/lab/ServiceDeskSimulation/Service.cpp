/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: October 14, 2017
 * File: Service.cpp
 * Purpose: Service Desk Simulation.
 *          Module 02 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: Service class
 */

#include "Service.h"

Service::Service(Priority _priority, double _duration) {
    priority = _priority;
    duration = _duration;
}

Service::Service(const Service& orig) {
}

Service::~Service() {
}

Priority Service::getPriority() {
    return priority;
}

double Service::getDuration() {
    return duration;
}

void Service::setCustomer(Customer* _customer) {
    customer = _customer;
}

std::string Service::getPriorityDescription() {
    std::string description;
    
    switch (priority) {
        case Priority::high:
            description = "High";
            break;
        case Priority::medium:
            description = "Medium";
            break;
        case Priority::low:
            description = "Low";
            break;
        default:
            description = "";
            break;
    }
    
    return description;
}
