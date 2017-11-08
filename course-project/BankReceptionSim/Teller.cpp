
#include <cstdlib>
#include "Teller.h"

Teller::Teller(int _desk) {
    desk = _desk;
    busy = false;
    transaction = NULL;
}

Teller::Teller(const Teller& orig) {
}

Teller::~Teller() {
}

int Teller::getDesk() {
    return desk;
}

bool Teller::isBusy() {
    return busy;
}

void Teller::startService(Transaction* t) {
    busy = true;
    transaction = t;
}

void Teller::endService() {
    busy = false;
    transaction = NULL;
}
