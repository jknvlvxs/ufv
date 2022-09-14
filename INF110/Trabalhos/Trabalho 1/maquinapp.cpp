#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int produto, valorInserido = 1, somaValor = 0;
    char tipoValor;

    cin >> produto; // 1, 2 ou 3
    int precos[3] = {430, 270, 143};

    int cedulas[6] = {10000, 5000, 2000, 1000, 500, 200};
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    
    while (valorInserido != 0){
        cin >> tipoValor;
        cin >> valorInserido;
        somaValor = somaValor + (tipoValor == 'M' ? valorInserido : valorInserido * 100);
    }

    if(produto >= 1 && produto <= 3){
        if (somaValor < precos[produto-1]) {
            cout << "Saldo insuficiente." << endl;
        } else {
            int troco = somaValor - precos[produto-1];
            while (troco != 0) {
                for(int i = 0; i < 6; i++){
                    while(troco >= cedulas[i]){
                        cout << "C " << cedulas[i]/100 << endl;
                        troco = troco - cedulas[i];
                    }   
                }
                
                for(int i = 0; i < 6; i++){
                    while(troco >= moedas[i]){
                        cout << "M " << moedas[i] << endl;
                        troco = troco - moedas[i];
                    }   
                }
            } 
        }
    } else {
        cout << "Produto inexistente." << endl;
    }
    
    return 0;
}