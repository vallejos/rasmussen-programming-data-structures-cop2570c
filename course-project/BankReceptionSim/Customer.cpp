
#include "Customer.h"

Customer::Customer() {
    id = 0;
    firstName = "";
    lastName = "";
    account = "";
    leaveAt = 0;
    enterAt = 0;
    serviceAt = 0;
}

Customer::Customer(int _id, string _firstName, string _lastName) {
    id = _id;
    firstName = _firstName;
    lastName = _lastName;
    account = "";
    leaveAt = 0;
    enterAt = 0;
    serviceAt = 0;
}

Customer::Customer(const Customer& orig) {
}

Customer::~Customer() {
}

int Customer::getId() {
    return id;
}

string Customer::getLastName() {
    return lastName;
}

string Customer::getFirstName() {
    return firstName;
}

string Customer::getAccount() {
    return account;
}

void Customer::setAccount(string _account) {
    account = _account;
}

void Customer::setEnterAt(int _timestamp) {
    enterAt = _timestamp;
}

void Customer::setServiceAt(int _timestamp) {
    serviceAt = _timestamp;
}

void Customer::setLeaveAt(int _timestamp) {
    leaveAt = _timestamp;
}

int Customer::getEnterAt() {
    return enterAt;
}

int Customer::getServiceAt() {
    return serviceAt;
}

int Customer::getLeaveAt() {
    return leaveAt;
}

int Customer::getWaitingTime() {
    return serviceAt - enterAt;
}

int Customer::getTotalServiceTime() {
    return leaveAt - enterAt;
}

void Customer::setTransaction(Transaction* t) {
    transaction = t;
}

Transaction* Customer::getTransaction() {
    return transaction;
}
