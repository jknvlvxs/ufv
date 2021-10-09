#include "split.h"

Split::Split() {}

Split::Split(string ticker, string date, int x, int y):
   _ticker(ticker), _date(date), _x(x), _y(y) {}

string Split::getTicker() {
    return _ticker;
}

string Split::getDate() {
    return _date;
}

int Split::getSplitX() {
    return _x;
}

int Split::getSplitY() {
    return _y;
}