#include <iostream>

using namespace std;

int main () {

    int numeros[10];
    char *verificador = "Ordenado";

    for (int i = 0; i < 10; i++){
        cin >> numeros[i];
    }

    for (int i = 0; i < 9; i++){
        if(numeros[i] > numeros[i+1]) verificador = "Desordenado";
    }
    
    cout << verificador << endl;

    return 0;
}