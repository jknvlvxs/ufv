#include "price.h"

Price::Price() {}

Price::Price(string ticker, string date, int value):
   _ticker(ticker), _date(date), _value(value) {}

string Price::getTicker() {
    return _ticker;
}

string Price::getDate() {
    return _date;
}

int Price::getValue() {
    return _value;
}