#include "earnings.h"

Earnings::Earnings() {}

Earnings::Earnings(string ticker, string date, double dividends):
   _ticker(ticker), _date(date), _dividends(dividends) {}

string Earnings::getTicker() {
    return _ticker;
}

string Earnings::getDate() {
    return _date;
}

double Earnings::getDividends() {
    return _dividends;
}