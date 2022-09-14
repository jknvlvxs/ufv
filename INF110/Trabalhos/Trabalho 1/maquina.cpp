#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int preco, valorInserido = 1, somaValor = 0;

    cin >> preco;
    
    while (valorInserido != 0){
        cin >> valorInserido;
        somaValor = somaValor + valorInserido;
    }

    if (somaValor >= preco){
        cout << "Troco de " << somaValor - preco << " centavos." << endl;
    } else {
        cout << "Saldo insuficiente." << endl;
    }
    
    return 0;
}