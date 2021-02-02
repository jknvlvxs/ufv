#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int produto, valorInserido = 1, somaValor = 0;
    char tipoValor;

    cin >> produto; // 1, 2 ou 3
    int precos[3] = {430, 270, 143};
    
    while (valorInserido != 0){
        cin >> tipoValor;
        cin >> valorInserido;
        somaValor = somaValor + (tipoValor == 'M' ? valorInserido : valorInserido * 100);
    }

    if(produto >= 1 && produto <= 3){
        if (somaValor >= precos[produto-1]){
            cout << "Troco de " << somaValor - precos[produto-1] << " centavos." << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    } else {
        cout << "Produto inexistente." << endl;
    }
    
    return 0;
}