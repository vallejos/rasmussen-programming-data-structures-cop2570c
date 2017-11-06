/**
 * Author: Leonardo Vallejos <leonardofabian.hernandezvallej@smail.rasmussen.edu>
 * Date: November 5, 2017
 * File: Event.cpp
 * Purpose: Infix, Prefix, Postfix demo with Stacks.
 *          Module 01 Lab Assignment for COP2570C Programming Data Structures course at Rasmussen College.
 * Description: main program
 */

#include "Event.h"

Event::Event(EventType _type, int _timestamp) {
    type = _type;
    createdAt = _timestamp;
    dispatchedAt = 0;
    dispatched = false;
}

Event::Event(const Event& orig) {
}

Event::~Event() {
}

EventType Event::getType() {
    return type;
}

bool Event::isDispatched() {
    return dispatched;
}

bool Event::dispatch(int _timestamp) {
    dispatched = true;
    dispatchedAt = _timestamp;
    
    return dispatched;
}
