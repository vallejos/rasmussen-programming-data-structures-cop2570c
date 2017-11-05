
#include "Customer.h"

Customer::Customer() {
    id = 0;
    firstName = "";
    lastName = "";
}

Customer::Customer(int _id, string _firstName, string _lastName) {
    id = _id;
    firstName = _firstName;
    lastName = _lastName;
}

Customer::Customer(const Customer& orig) {
}

Customer::~Customer() {
}
