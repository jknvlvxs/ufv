#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <string>
using namespace std;

class Operations {
    protected:
        string _operation_type; // tipo de operação (compra, venda, consulta)
        string _ticker;
        string _date;
        int _quantity; // quantidade de valor da operação 
    public:
        Operations();
        Operations(string operation_type, string ticker, string date);
        Operations(string operation_type, string ticker, string date, int quantity);
        
        string getOperationType();
        string getTicker();
        string getDate();
        int getQuantity();
};

#endif