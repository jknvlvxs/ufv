#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int numeroA, numeroB, aux;

    cin >> numeroA >> numeroB;

    if(numeroB < numeroA){
        aux = numeroA;
        numeroA = numeroB;
        numeroB = aux;
    }

    cout << "Numeros pares: ";

    for(int i = numeroA; i <= numeroB; i++){
        if(i % 2 == 0){
            cout << i << " ";
        }

        if (i == numeroB) cout << endl;
    }
        
    return 0;
}