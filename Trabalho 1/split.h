#ifndef SPLIT_H
#define SPLIT_H

#include <string>
using namespace std;

class Split {
    protected:
        string _ticker;
        string _date;
        int _x; // split x:y
        int _y; // split x:y
    public:
        Split();
        Split(string ticker, string date, int x, int y);
        
        string getTicker();
        string getDate();
        int getSplitX();
        int getSplitY();
};

#endif