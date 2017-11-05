
#include "Teller.h"

Teller::Teller(int _desk) {
    desk = _desk;
    active = false;
}

Teller::Teller(const Teller& orig) {
}

Teller::~Teller() {
}

int Teller::getDesk() {
    return desk;
}

bool Teller::isActive() {
    return active;
}

void Teller::setActive() {
    active = true;
}

void Teller::setInactive() {
    active = false;
}
