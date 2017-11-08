
#include <string>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(TransactionType _type) {
    type = _type;
    amount = 0;
    duration = 0;
}

//Transaction::Transaction(TransactionType _type, Customer* _customer) {
//    type = _type;
//    customer = _customer;
//    amount = 0;
//    duration = 0;
//}

Transaction::Transaction(const Transaction& orig) {
}

Transaction::~Transaction() {
}

string Transaction::getType() {
    string t = "";
    switch (type) {
        case TransactionType::open:
            t = "open";
            break;
        case TransactionType::close:
            t = "close";
            break;
        case TransactionType::deposit:
            t = "deposit";
            break;
        case TransactionType::withdraw:
        default:
            t = "withdraw";
            break;
    }

    return t;
}

//Customer* Transaction::getCustomer() {
//    return customer;
//}

int Transaction::getDuration() {
    return duration;
}

void Transaction::setDuration(int _duration) {
    duration = _duration;
}

double Transaction::getAmount() {
    return amount;
}

void Transaction::setAmount(double _amount) {
    amount = _amount;
}
