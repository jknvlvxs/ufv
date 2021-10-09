#ifndef Wallet_H
#define Wallet_H

#include <string>
#include "split.h"
#include "earnings.h"

using namespace std;

class Wallet {
    protected:
        string _ticker;
        int _quantity; // total de ações
        int _current_value; // valor atual da ação
        int _cost; // custo total das ações
        int _dividends; // valor obtido com dividendos
        double _soma_dividends = 0; // soma dos dividendos diários para reinvestimento
        int _operations; // valor obtido com operações
    public:
        Wallet();
        Wallet(string ticker, int quantity, int current_value, int cost, int dividends, int operations);

        string getTicker();
        int getQuantity();
        int getCurrentValue();
        int getCost();
        int getDividends();
        int getOperations();

        void setCurrentValue(int value);
        void setOperations(int value);
        void setDividends(int value);
        
        void purchase(int quantity, int price);
        void sale(int quantity, int price);
        void split(Split split);
        void earning(Earnings earning);
        void reinvest(int price);
};

#endif