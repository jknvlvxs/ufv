#include <iostream>
using namespace std;

int main () {
    int numero, soma;
    bool resultado = false;

    cin >> numero;

    for(int i = 1; i < numero; i++){
        soma = i;
        for(int j = 2; j < numero; j++){
            if(i < j){
                soma += j;
                if(soma == numero){
                    resultado = true;
                    break;
                }
            }
        }
    }

    if(resultado == true){
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    } 

    return 0;
}