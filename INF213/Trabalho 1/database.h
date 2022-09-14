#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "price.h"
#include "split.h"
#include "earnings.h"
#include "operations.h"
#include "event.h"

using namespace std;

class Database {
    protected:
        string _path_precos;
        string _path_splits;
        string _path_dividendos;
        string _path_operacoes;
        string _output_type;
        string *csv_line = new string[500000];
        
        int _price_size = 0;
        int _split_size = 0;
        int _earnings_size = 0;
        int _operations_size = 0;
        int _event_size = 0;

        int leituraCSV(string path);
        void createPrices();
        void createSplit();
        void createEarnings();
        void createOperations();
        void createEvent();
        int particionaPreco(Price *v, int beg, int end, int pivo);
        int particionaOperations(Operations *v, int beg, int end, int pivo);
        int particionaEvent(Event *v, int beg, int end, int pivo);
        void quickSortPreco(Price *v, int beg, int end);
        void quickSortOperations(Operations *v, int beg, int end);
        void quickSortEvent(Event *v, int beg, int end);
    public:
        Price *price_history = new Price[500000];
        Split *split_history = new Split[500000];
        Earnings *earnings_history = new Earnings[500000];
        Operations *operations_list = new Operations[500000];
        Event *event_list = new Event[1500000];

        Database(string path_precos, string path_splits, string path_dividendos, string path_operacoes);
        ~Database();
        
        int getPriceSize();
        int getSplitSize();
        int getEarningsSize();
        int getOperationsSize();
        int getEventSize();
        string getOutputType();
};

#endif