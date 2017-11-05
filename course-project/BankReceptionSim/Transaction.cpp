
#include "Transaction.h"

Transaction::Transaction(TransactionType _type, Customer* _customer) {
    type = _type;
    customer = _customer;
}

Transaction::Transaction(const Transaction& orig) {
}

Transaction::~Transaction() {
}

TransactionType Transaction::getType() {
    return type;
}

Customer* Transaction::getCustomer() {
    return customer;
}

double Transaction::getDuration() {
    return duration;
}

void Transaction::setDuration(double _duration) {
    duration = _duration;
}
