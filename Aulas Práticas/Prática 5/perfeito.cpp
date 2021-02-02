#include <iostream>

using namespace std;

int main () {
    int numero, soma = 0;

    cin >> numero;

    for(int i = numero-1; i >= 1; i--){
        if(numero % i == 0){
            soma = soma + i;
        }
    }

    if (soma == numero)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
        
    return 0;
}