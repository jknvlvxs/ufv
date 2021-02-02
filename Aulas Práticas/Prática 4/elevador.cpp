#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int leituras = 0, capacidade = 0, saidas = 0, entradas = 0, qtdPessoas = 0, validador = 0;

    cin >> leituras >> capacidade;

    for(int i = 1; i <= leituras; i++){
        cin >> saidas >> entradas;
        qtdPessoas = qtdPessoas - saidas + entradas;
        if (qtdPessoas > capacidade) validador = 1;
    }

    if (validador == 0) cout << "N" << endl;
    else cout << "S" << endl;
    
    return 0;
}