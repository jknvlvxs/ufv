#include "wallet.h"

Wallet::Wallet() {}

Wallet::Wallet(string ticker, int quantity, int current_value, int cost, int dividends, int operations):
  _ticker(ticker), _quantity(quantity), _current_value(current_value), _cost(cost), _dividends(dividends), _operations(operations) {}

string Wallet::getTicker() {
    return _ticker;
}

int Wallet::getQuantity() {
    return _quantity;
}

int Wallet::getCurrentValue() {
    return _current_value;
}

int Wallet::getCost() {
    return _cost;
}

int Wallet::getDividends() {
    return _dividends;
}

int Wallet::getOperations() {
    return _operations;
}

void Wallet::setDividends(int value) {
    _dividends = value;
}

void Wallet::setOperations(int value) {
    _operations = value;
}

void Wallet::setCurrentValue(int value){
    _current_value = value;
}

void Wallet::purchase(int quantity, int price){
    _quantity += quantity;
    _cost += quantity * price;
}

void Wallet::sale(int quantity, int price){
    int medium_cost = (quantity * _cost) / _quantity;
    _operations += (quantity * price - medium_cost);
    _quantity -= quantity;
    _cost -= medium_cost;
}

void Wallet::split(Split split){
    _quantity = _quantity * split.getSplitX() / split.getSplitY();
}

void Wallet::earning(Earnings earning){
    double calculate_dividends = _quantity * earning.getDividends();
    _dividends += calculate_dividends * 100;
    _soma_dividends += calculate_dividends * 100;
}

void Wallet::reinvest(int price){
    if(_soma_dividends != 0){
        int quantity = _soma_dividends / price;
        purchase(quantity, price);
        _soma_dividends = 0;
    }
}