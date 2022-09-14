#include "operations.h"

Operations::Operations() {}

Operations::Operations(string operation_type, string ticker, string date):
   _operation_type(operation_type), _ticker(ticker), _date(date) {}

Operations::Operations(string operation_type, string ticker, string date, int quantity):
   _operation_type(operation_type), _ticker(ticker), _date(date), _quantity(quantity) {}

string Operations::getOperationType() {
    return _operation_type;
}

string Operations::getTicker() {
    return _ticker;
}

string Operations::getDate() {
    return _date;
}

int Operations::getQuantity() {
    return _quantity;
}