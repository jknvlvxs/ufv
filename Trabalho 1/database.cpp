#include "database.h"
#include "price.h"
#include <fstream>
#include <sstream>

Database::Database(string path_precos, string path_splits, string path_dividendos, string path_operacoes):
    _path_precos(path_precos), _path_splits(path_splits), _path_dividendos(path_dividendos), _path_operacoes(path_operacoes) {
        _price_size = leituraCSV(_path_precos);
        createPrices();
        quickSortPreco(price_history, 0, _price_size);
        fill(csv_line->begin(), csv_line->end(), ' ');

        _split_size = leituraCSV(_path_splits);
        createSplit();
        fill(csv_line->begin(), csv_line->end(), ' ');
        
        _earnings_size = leituraCSV(_path_dividendos);
        createEarnings();
        fill(csv_line->begin(), csv_line->end(), ' ');

        _operations_size = leituraCSV(_path_operacoes);
        _output_type = csv_line[0]; _operations_size--;
        createOperations();
        fill(csv_line->begin(), csv_line->end(), ' ');

        createEvent();
        quickSortEvent(event_list, 0, _event_size);
}

/* Função que realiza leitura do CSV */
int Database::leituraCSV(string path){
    fstream fin(path);
  
    if(!fin.is_open()) throw std::runtime_error("Could not open file");

    string line;
    int line_counter = 0;
  
    while (fin.good()) {
        getline(fin, line);

        if(line.size() > 0){
            csv_line[line_counter] = line;
            line_counter++;
        }
    }

    fin.close();
    return line_counter;
}

/* Função que cria os preços e adiciona ao vetor */
void Database::createPrices(){
    for(int i = 0; i < _price_size; i++){
        stringstream s(csv_line[i]);

        int word_counter = 0;
        string word;

        string ticker, date;
        double value = 0;

        while (getline(s, word, ',')) {
            if(word_counter == 0)
                ticker = word;
            else if(word_counter == 1)
                date = word;
            if(word_counter == 5)
                value = stod(word) * 100 + 0.000001;

            Price new_price(ticker, date, value);
            price_history[i] = new_price;
            word_counter++;
        }
    }
}

/* Função que cria os splits e adiciona ao vetor */
void Database::createSplit(){
    for(int i = 0; i < _split_size; i++) {
        stringstream s(csv_line[i]);

        int word_counter = 0;
        string word;

        string ticker, date;
        int x = 0, y = 0;

        while (getline(s, word, ',')) {
            if(word_counter == 0)
                ticker = word;
            else if(word_counter == 1)
                date = word;
            if(word_counter == 2) {
                x = stoi(word.substr(0, word.find(':')));
                y = stoi(word.substr(word.find(':')+1));
            }

            Split new_split(ticker, date, x, y);
            split_history[i] = new_split;
            word_counter++;
        }
    }
}

/* Função que cria os dividendos e adiciona ao vetor */
void Database::createEarnings(){
    for(int i = 0; i < _earnings_size; i++) {
        stringstream s(csv_line[i]);

        int word_counter = 0;
        string word;

        string ticker, date;
        double dividends = 0;

        while (getline(s, word, ',')) {
            if(word_counter == 0)
                ticker = word;
            else if(word_counter == 1)
                date = word;
            if(word_counter == 2)
                dividends = stod(word);

            Earnings new_earnings(ticker, date, dividends);
            earnings_history[i] = new_earnings;
            word_counter++;
        }
    }
}

/* Função que cria as operações e adiciona ao vetor */
void Database::createOperations(){
    for(int i = 1; i <= _operations_size; i++) {
        stringstream s(csv_line[i]);

        int word_counter = 0;
        string word;

        string operation_type, ticker, date;
        int stock_quantity = 0;

        while (getline(s, word, ',')) {
            if(word_counter == 0)
                date = word;
            else if(word_counter == 1)
                operation_type = word;
            else if(word_counter == 2)
                ticker = word;
            if(csv_line[0] != "Q" && word_counter == 3)
                stock_quantity = stoi(word);

            Operations new_operations(operation_type, ticker, date, stock_quantity);
            operations_list[i-1] = new_operations;
            word_counter++;
        }
    }
}

/* Função que cria os eventos na ordem: dividendos, split, operações e reinvestimento */
void Database::createEvent(){
    for(int i = 0; i < _earnings_size; i++){
        Event new_event(1, earnings_history[i].getTicker(), earnings_history[i].getDate(), i);
        event_list[_event_size] = new_event;
        _event_size++;
    }
    for(int i = 0; i < _split_size; i++){
        Event new_event(2, split_history[i].getTicker(), split_history[i].getDate(), i);
        event_list[_event_size] = new_event;
        _event_size++;
    }
    for(int i = 0; i < _operations_size; i++){
        Event new_event(3, operations_list[i].getTicker(), operations_list[i].getDate(), i);
        event_list[_event_size] = new_event;
        _event_size++;
    }
    for(int i = 0; i < _earnings_size; i++){
        Event new_event(4, earnings_history[i].getTicker(), earnings_history[i].getDate(), i);
        event_list[_event_size] = new_event;
        _event_size++;
    }
}

/* Função que ordena preço das ações com base no ticker e na data */
int Database::particionaPreco(Price *v, int beg, int end, int pivo) {
    Price valorPivo = v[pivo];
    swap(v[pivo], v[end-1]);
    int pos = beg;

    for(int i = beg; i < end-1; i++) {
        if(v[i].getTicker() != valorPivo.getTicker()){
            if(v[i].getTicker() < valorPivo.getTicker()){
                swap(v[pos], v[i]); 
                pos++;  
            }
        } else {
            if(v[i].getDate() < valorPivo.getDate()){
                swap(v[pos], v[i]); 
                pos++;  
            }
        }
    }

    swap(v[pos],v[end-1]);
    return pos;
}

void Database::quickSortPreco(Price *v, int beg, int end) {
    if(beg == end)
        return;
    int pos = particionaPreco(v, beg, end, beg); 
    quickSortPreco(v, beg, pos);
    quickSortPreco(v, pos + 1, end);
}

/* Função que ordena as operações com base na data */
int Database::particionaOperations(Operations *v, int beg, int end, int pivo) {
    Operations valorPivo = v[pivo];
    swap(v[pivo], v[end-1]);
    int pos = beg;

    for(int i = beg; i < end-1; i++) {
        if(v[i].getDate() < valorPivo.getDate()){
            swap(v[pos], v[i]); 
            pos++;  
        }
    }

    swap(v[pos],v[end-1]);
    return pos;
}

void Database::quickSortOperations(Operations *v, int beg, int end) {
    if(beg == end)
        return;
    int pos = particionaOperations(v, beg, end, beg); 
    quickSortOperations(v, beg, pos);
    quickSortOperations(v, pos + 1, end);
}

/* Função que ordena as eventos com base na data e no tipo (ordem de prioridade) */
int Database::particionaEvent(Event *v, int beg, int end, int pivo) {
    Event valorPivo = v[pivo];
    swap(v[pivo], v[end-1]);
    int pos = beg;

    for(int i = beg; i < end-1; i++) {
        if(v[i].getDate() != valorPivo.getDate()){
            if(v[i].getDate() < valorPivo.getDate()){
                swap(v[pos], v[i]); 
                pos++;  
            }
        } else {
            if(v[i].getType() < valorPivo.getType()){
                swap(v[pos], v[i]); 
                pos++;  
            }
        }
    }

    swap(v[pos],v[end-1]);
    return pos;
}

void Database::quickSortEvent(Event *v, int beg, int end) {
    if(beg == end)
        return;
    int pos = particionaEvent(v, beg, end, beg); 
    quickSortEvent(v, beg, pos);
    quickSortEvent(v, pos + 1, end);
}

int Database::getPriceSize() {
    return _price_size;
}

int Database::getSplitSize() {
    return _split_size;
}

int Database::getEarningsSize() {
    return _earnings_size;
}

int Database::getOperationsSize() {
    return _operations_size;
}

int Database::getEventSize() {
    return _event_size;
}

string Database::getOutputType() {
    return _output_type;
}

Database::~Database(){
    delete []csv_line;
    delete []price_history;
    delete []split_history;
    delete []earnings_history;
    delete []operations_list;
    delete []event_list;
}