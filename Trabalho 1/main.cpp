#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>

#include "price.h"
#include "split.h"
#include "earnings.h"
#include "operations.h"
#include "database.h"
#include "wallet.h"

using namespace std;

/* Função que realiza uma busca binária para retornar a posição do preço de uma ação em determinada data */
int buscaPrice(Price *array, int begin, int end, string ticker, string date) {
	if (begin > end) return -1;
	
    int meio = (end-begin)/2 + begin;

	if (array[meio].getTicker() == ticker) { 
        if (array[meio].getDate() == date) 
            return meio;
        else {
            if(array[meio].getDate() < date) 
                return buscaPrice(array,meio+1, end, ticker, date);
            else 
                return buscaPrice(array,begin, meio-1, ticker, date); 
        } 
	}

	if (array[meio].getTicker() > ticker)
		return buscaPrice(array,begin, meio-1, ticker, date); 

	return buscaPrice(array,meio+1, end, ticker, date); 	
}

/* Função que realiza uma busca binária para retornar o dia de fechamento do mês passado como parâmetro */
string getLastDatefromMonth(Price *array, int begin, int end, string ticker, int year, int month) {
	if (begin > end) return array[begin].getDate();
	
    int meio = (end-begin)/2 + begin;
    int month_meio = stoi(array[meio].getDate().substr(5, 2));
    int year_meio = stoi(array[meio].getDate().substr(0, 4));
    int month_next = stoi(array[meio+1].getDate().substr(5, 2));

    if (array[meio].getTicker() == ticker) { 
        if(year_meio == month){
            if(month_meio == year){
                if(month_next != year){
                    if (month_meio == year) 
                        return array[meio].getDate();
                    else if(month_meio < year) 
                        return getLastDatefromMonth(array,meio+1, end, ticker, year, month);
                    else 
                        return getLastDatefromMonth(array,begin, meio-1, ticker, year, month); 
                } else {
                    if(array[meio+1].getTicker() != ticker) 
                        return getLastDatefromMonth(array,begin, meio-1, ticker, year, month);
                    else 
                        return getLastDatefromMonth(array,meio+1, end, ticker, year, month);
                }
            }

            if(month_meio > year)
                return getLastDatefromMonth(array,begin, meio-1, ticker, year, month); 

            if(month_meio < year)
                return getLastDatefromMonth(array,meio+1, end, ticker, year, month); 
        }

        if(year_meio > month)
            return getLastDatefromMonth(array,begin, meio-1, ticker, year, month); 

        if(year_meio < month)
            return getLastDatefromMonth(array,meio+1, end, ticker, year, month); 
	}

	if (array[meio].getTicker() > ticker)
		return getLastDatefromMonth(array,begin, meio-1, ticker, year, month); 

	return getLastDatefromMonth(array,meio+1, end, ticker, year, month); 	
}

/* Função que verifica se existe determinada ação na carteira.
    Caso sim, retorna o id dessa ação;
    Caso não, retorna o tamanho do array, que será a posição para inserir a nova ação na carteira */
int insertWallet(Wallet *wallet, int wallet_size, string ticker) {
    for(int j = 0; j < wallet_size; j++)
        if(wallet[j].getTicker() == ticker)
            return j;

    return wallet_size; 
}

/* Função para ordenar wallet 
    wallet_type = 0 | wallet total, ordenada em ordem decrescente de rentabilidade total
    wallet_type = 1 | wallet mensal, ordenada em ordem decrescente de lucro total obtido por cada ação no mês */
int particionaWallet(Wallet *v, int beg, int end, int pivo, int wallet_type){
    Wallet valorPivo = v[pivo];

    swap(v[pivo], v[end-1]);

    int pos = beg;
    
    for(int i = beg; i < end-1; i++) {
        if(wallet_type == 1){ // wallet mensal
            int v1 = v[i].getDividends() + v[i].getOperations();
            int v2 = valorPivo.getDividends() + valorPivo.getOperations();
            if(v1 != v2){
                if(v1 > v2){
                    swap(v[pos], v[i]); 
                    pos++;  
                }
            } else {
                if(v[i].getTicker() < valorPivo.getTicker()){
                    swap(v[pos], v[i]); 
                    pos++;  
                }
            }
        } else { // wallet total
            long long int v1 = ((v[i].getCurrentValue() * (long long) v[i].getQuantity() - v[i].getCost()) + v[i].getDividends() + v[i].getOperations());
            long long int v2 = ((valorPivo.getCurrentValue() * (long long) valorPivo.getQuantity() - valorPivo.getCost()) + valorPivo.getDividends() + valorPivo.getOperations());
            if(v1 != v2){
                if(v1 > v2){
                    swap(v[pos], v[i]); 
                    pos++;  
                }
            } else {
                if(v[i].getTicker() < valorPivo.getTicker()){
                    swap(v[pos], v[i]); 
                    pos++;  
                }
            }
        }       
    }
    //coloque o pivo depois do ultimo elemento menor que ele
    swap(v[pos],v[end-1]);
    return pos;
}

void ordernaWallet(Wallet *v, int beg, int end, int tipo){
    if(beg == end)
        return;

    int pos = particionaWallet(v, beg, end, beg, tipo); 
    ordernaWallet(v, beg, pos, tipo);
    ordernaWallet(v, pos + 1, end, tipo);
}

int main(int argc, char**argv) {
    /* Database é a classe que armazena todos os array preenchidos com dados vindo dos arquivos */
    Database *database = new Database(argv[1], argv[2], argv[3], argv[4]);
    
    /* Wallet são as carteiras onde são adicionadas as ações */
    
    /* wallet é a carteira que soma os valores totais */
    Wallet *wallet = new Wallet[1000];
    int wallet_size = 0;
    /* mensal_wallet é a carteira que soma os valores mensalmente */
    Wallet *mensal_wallet = new Wallet[1000];
    int mensal_wallet_size = 0;

    /* output é o código de identificação da saída */
    string output(1, database->getOutputType()[0]);
    /* reinvest é o código que define o reinvestimento */
    string reinvest(1, database->getOutputType()[1]);

    // for(int i = 0; i < database->getPriceSize(); i++)
        // cout << database->price_history[i].getTicker() << " | " << database->price_history[i].getDate() << " | " << database->price_history[i].getValue() << endl;
    
    // for(int i = 0; i < database->getSplitSize(); i++)
        // cout << database->split_history[i].getTicker() << " | " << database->split_history[i].getDate() << " | " << database->split_history[i].getSplitX() << ":" << database->split_history[i].getSplitY() << endl;

    // for(int i = 0; i < database->getEarningsSize(); i++)
        // cout << database->earnings_history[i].getTicker() << " | " << database->earnings_history[i].getDate() << " | " << database->earnings_history[i].getDividends() << endl;
    
    // for(int i = 0; i < database->getOperationsSize(); i++)
        // cout << database->operations_list[i].getTicker() << " | " << database->operations_list[i].getDate() << " | " << database->operations_list[i].getOperationType() << " | " << database->operations_list[i].getStockQuantity() << endl;

    // for(int i = 0; i < database->getEventSize(); i++)
        // cout << database->event_list[i].getTicker() << " | " << database->event_list[i].getDate() << " | " << database->event_list[i].getType() << endl;

    if(output == "Q"){
        for(int i = 0; i < database->getOperationsSize(); i++){
            int price_operation = buscaPrice(database->price_history, 0, database->getPriceSize(), database->operations_list[i].getTicker(), database->operations_list[i].getDate());
            cout << database->price_history[price_operation].getValue() << endl;
        }
    } else {
        int first_month = stoi(database->operations_list[0].getDate().substr(5, 2));
        int first_year = stoi(database->operations_list[0].getDate().substr(0, 4));
        int last_month = stoi(database->price_history[database->getPriceSize()-1].getDate().substr(5, 2));
        int last_year = stoi(database->price_history[database->getPriceSize()-1].getDate().substr(0, 4));
        
        for(int y = first_year; y <= last_year; y++){
            for(int m = ((y == first_year) ? first_month : 1); m <= ((y == last_year) ? last_month : 12); m++){
                /* closing_day é o dia de fechamento do mês */
                string closing_day = getLastDatefromMonth(database->price_history, 0, database->getPriceSize(), database->price_history[0].getTicker(), m, y);
                
                /* Laço de repetição que percorre toda a lista de eventos */
                for(int i = 0; i < database->getEventSize(); i++){
                    int month = stoi(database->event_list[i].getDate().substr(5, 2));
                    int year = stoi(database->event_list[i].getDate().substr(0, 4));
                    string ticker = database->event_list[i].getTicker();

                    if(m == month && y == year){
                        int pos = insertWallet(wallet, wallet_size, ticker);
                        int mensal_pos = insertWallet(mensal_wallet, mensal_wallet_size, ticker);

                        int id = database->event_list[i].getId();

                        if(database->event_list[i].getType() == 3){
                            /* Caso o evento seja uma operação (compra ou venda) */
                            
                            if(pos == wallet_size){
                                Wallet new_wallet(ticker, 0, 0, 0, 0, 0);
                                wallet[wallet_size] = new_wallet;
                                wallet_size++;
                            }

                            if(mensal_pos == mensal_wallet_size){
                                Wallet new_wallet(ticker, 0, 0, 0, 0, 0);
                                mensal_wallet[mensal_wallet_size] = new_wallet;
                                mensal_wallet_size++;
                            }
                            
                            int price_operation = buscaPrice(database->price_history, 0, database->getPriceSize(), ticker, database->operations_list[id].getDate());
                            int value = database->price_history[price_operation].getValue();
                            int quantity = database->operations_list[id].getQuantity();

                            if(database->operations_list[id].getOperationType() == "C"){
                                wallet[pos].purchase(quantity, value);
                                mensal_wallet[mensal_pos].purchase(quantity, value);
                            } else if(database->operations_list[id].getOperationType() == "V"){
                                wallet[pos].sale(quantity, value);
                                mensal_wallet[mensal_pos].sale(quantity, value);
                            }
                        } else if (pos < wallet_size && mensal_pos < mensal_wallet_size && database->event_list[i].getType() == 1){
                            /* Caso o evento seja um pagamento de dividendo */
                            wallet[pos].earning(database->earnings_history[id]);
                            mensal_wallet[mensal_pos].earning(database->earnings_history[id]);
                        } else if (pos < wallet_size && mensal_pos < mensal_wallet_size && database->event_list[i].getType() == 2){
                            /* Caso o evento seja um split */
                            wallet[pos].split(database->split_history[id]);
                            mensal_wallet[mensal_pos].split(database->split_history[id]);
                        } else if (reinvest == "R" && pos < wallet_size && mensal_pos < mensal_wallet_size && database->event_list[i].getType() == 4){
                            /* Caso o evento seja um reinvestimento */
                            int id_price = buscaPrice(database->price_history, 0, database->getPriceSize(), database->earnings_history[id].getTicker(), database->earnings_history[id].getDate());
                            wallet[pos].reinvest(database->price_history[id_price].getValue());
                            mensal_wallet[mensal_pos].reinvest(database->price_history[id_price].getValue());
                        }
                    }
                }

                if(output != "F"){
                    int ano = stoi(closing_day.substr(0, 4));
                    int mes = stoi(closing_day.substr(5, 2));
                    int dia = stoi(closing_day.substr(8, 2));

                    if(output == "D")
                        cout << setfill('+') << setw(110) << "+" << endl << endl;
                    
                    cout << "Fechamento do mes (" << ano << "-" << mes << "-" << dia << ")" << endl;

                    if(output == "D")
                        cout << setfill('-') << setw(80) << "-" << endl;
                }

                /* Ordenação das carteiras */ 
                if(output == "D" || output == "M"){
                    for(int w = 0; w < mensal_wallet_size; w++){
                        int id_month_price = buscaPrice(database->price_history, 0, database->getPriceSize(), mensal_wallet[w].getTicker(), closing_day);
                        int current_value = database->price_history[id_month_price].getValue();
                        mensal_wallet[w].setCurrentValue(current_value);
                    }
                    
                    ordernaWallet(mensal_wallet, 0, mensal_wallet_size, 1);
                }

                if(output == "D" || output == "F"){
                    for(int w = 0; w < wallet_size; w++){
                        int id_month_price = buscaPrice(database->price_history, 0, database->getPriceSize(), wallet[w].getTicker(), closing_day);
                        int current_value = database->price_history[id_month_price].getValue();
                        wallet[w].setCurrentValue(current_value);
                    }

                    ordernaWallet(wallet, 0, wallet_size, 0);
                }

                /* Impressão das informações mensais */                
                long long int soma_div = 0, soma_op = 0;
                long long int soma_value = 0, soma_cost = 0, soma_appreciation = 0, soma_operations = 0, soma_dividends = 0, soma_total = 0;  

                if(output == "D"){
                    cout << right << setw(0) << setfill(' ') << "Acao";
                    cout << right << setw(16) << setfill(' ') << "Quantidade";
                    cout << right << setw(15) << setfill(' ') << "Valor Atual";
                    cout << right << setw(15) << setfill(' ') << "Custo Total";
                    cout << right << setw(15) << setfill(' ') << "Dividendos";
                    cout << right << setw(15) << setfill(' ') << "Operacoes" << endl;
                }
                
                for(int w = 0; w < mensal_wallet_size; w++){
                    long long int current_value = ((long long) wallet[w].getQuantity() * wallet[w].getCurrentValue());
                    
                    if(output == "D"){
                        cout << right << setw(0) << setfill(' ') << mensal_wallet[w].getTicker();
                        cout << right << setw(15) << setfill(' ') << mensal_wallet[w].getQuantity();
                        cout << right << setw(15) << setfill(' ') << current_value / 100;
                        cout << right << setw(15) << setfill(' ') << mensal_wallet[w].getCost() / 100;
                        cout << right << setw(15) << setfill(' ') << mensal_wallet[w].getDividends() / 100;
                        cout << right << setw(15) << setfill(' ') << mensal_wallet[w].getOperations() / 100 << endl;
                    }
                    
                    soma_div += mensal_wallet[w].getDividends();
                    soma_op += mensal_wallet[w].getOperations();
                    mensal_wallet[w].setDividends(0);
                    mensal_wallet[w].setOperations(0);
                }

                if(output == "D")
                    cout << setfill('-') << setw(80) << "-" << endl;

                if(output == "D" || output == "M"){
                    cout << right << setw(0) << setfill(' ') << "Lucro total do mes: ";
                    cout << right << setw(45) << setfill(' ') << soma_div / 100;
                    cout << right << setw(15) << setfill(' ') << soma_op / 100 << endl;
                    
                    if(output == "D")
                        cout << endl;
                }

                /* Impressão das informações totais */  
                if(output == "D"){
                    cout << "Totais ate hoje:" << endl;
                    cout << setfill('-') << setw(110) << "-" << endl;
                    
                    cout << right << setw(0) << setfill(' ') << "Acao";
                    cout << right << setw(16) << setfill(' ') << "Quantidade";
                    cout << right << setw(15) << setfill(' ') << "Valor Atual";
                    cout << right << setw(15) << setfill(' ') << "Custo Total";
                    cout << right << setw(15) << setfill(' ') << "Valorizacao";
                    cout << right << setw(15) << setfill(' ') << "Operacoes";
                    cout << right << setw(15) << setfill(' ') << "Dividendos";
                    cout << right << setw(15) << setfill(' ') << "Total" << endl;
                }
                
                for(int w = 0; w < wallet_size; w++){
                    long long int current_value = ((long long) wallet[w].getQuantity() * wallet[w].getCurrentValue());

                    if(output == "D"){
                        cout << right << setw(0) << setfill(' ') << wallet[w].getTicker();
                        cout << right << setw(15) << setfill(' ') << wallet[w].getQuantity();
                        cout << right << setw(15) << setfill(' ') << current_value / 100;
                        cout << right << setw(15) << setfill(' ') << wallet[w].getCost() / 100;
                        cout << right << setw(15) << setfill(' ') << (current_value - wallet[w].getCost()) / 100;
                        cout << right << setw(15) << setfill(' ') << wallet[w].getOperations() / 100;
                        cout << right << setw(15) << setfill(' ') << wallet[w].getDividends() / 100;
                        cout << right << setw(15) << setfill(' ') << ((current_value - wallet[w].getCost()) + wallet[w].getDividends() + wallet[w].getOperations()) / 100 << endl;
                    }
                    soma_value += current_value;
                    soma_cost += wallet[w].getCost();
                    soma_appreciation += (current_value - wallet[w].getCost());
                    soma_operations += wallet[w].getOperations();
                    soma_dividends += wallet[w].getDividends();
                    soma_total += ((current_value - wallet[w].getCost()) + wallet[w].getDividends() + wallet[w].getOperations());
                }

                if(output == "D")
                    cout << setfill('-') << setw(110) << "-" << endl;
                
                if(output == "D" || (output == "F" && last_month == m && last_year == y)){
                    cout << right << setw(0) << setfill(' ') << (output == "D" ? "Totais ate o momento:" : "Totais no final da simulacao:");
                    cout << right << setw(14) << setfill(' ') << soma_value/100;
                    cout << right << setw(15) << setfill(' ') << soma_cost/100;
                    cout << right << setw(15) << setfill(' ') << soma_appreciation/100;
                    cout << right << setw(15) << setfill(' ') << soma_operations/100;
                    cout << right << setw(15) << setfill(' ') << soma_dividends/100;
                    cout << right << setw(15) << setfill(' ') << soma_total / 100 << endl << endl;
                }
            }
        }
    }
    
    delete database;
    delete []wallet;
    delete []mensal_wallet;

    return 0;
}