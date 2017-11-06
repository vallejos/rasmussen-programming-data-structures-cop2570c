/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: vallejos
 *
 * Created on November 5, 2017, 9:26 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include "EventType.h"

class Event {
public:
    Event(EventType _type, int _timestamp);
    Event(const Event& orig);
    virtual ~Event();

    EventType getType();
    bool dispatch(int _timestamp);
    bool isDispatched();

protected:
    EventType type;
    int createdAt;
    int dispatchedAt;
    bool dispatched;

};

#endif /* EVENT_H */

