#include "event.h"

Event::Event() {}

Event::Event(int type, string ticker, string date, int id):
   _type(type), _ticker(ticker), _date(date), _id(id) {}

int Event::getType() {
    return _type;
}

string Event::getTicker() {
    return _ticker;
}

string Event::getDate() {
    return _date;
}

int Event::getId() {
    return _id;
}