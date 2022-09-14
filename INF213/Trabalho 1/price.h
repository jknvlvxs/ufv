#ifndef PRICE_H
#define PRICE_H

#include <string>
using namespace std;

class Price {
    protected:
        string _ticker;
        string _date;
        int _value; // preço da ação
    public:
        Price();
        Price(string ticker, string date, int value);
        
        string getTicker();
        string getDate();
        int getValue();
};

#endif