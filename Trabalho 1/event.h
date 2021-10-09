#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {
    protected:
        int _type; // tipo do evento (1-dividendos 2-split 3-operacoes 4-reinvestimentos)
        string _ticker;
        string _date;
        int _id; // id do evento em sua respectiva tabela
    public:
        Event();
        Event(int type, string ticker, string date, int id);

        int getType();
        string getTicker();
        string getDate();
        int getId();
};

#endif