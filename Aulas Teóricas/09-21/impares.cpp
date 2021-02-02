#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int numeroMaximo = 0, soma = 0, contador = 0, numeroAtual = 0;

    cin >> numeroMaximo;

    while (numeroMaximo > contador){
        if(numeroAtual % 2 != 0){
            soma = soma + numeroAtual;
            contador = contador + 1;

            if(contador == numeroMaximo){
                cout << numeroAtual << " = ";
            } else {
                cout << numeroAtual << " + ";
            }
        }
        numeroAtual = numeroAtual + 1;
    }

    cout << soma << endl;
    
    return 0;
}