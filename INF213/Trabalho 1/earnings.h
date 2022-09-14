#ifndef EARNINGS_H
#define EARNINGS_H

#include <string>
using namespace std;

class Earnings {
    protected:
        string _ticker;
        string _date;
        double _dividends;
    public:
        Earnings();
        Earnings(string ticker, string date, double dividends);
        
        string getTicker();
        string getDate();
        double getDividends();
};

#endif