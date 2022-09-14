#include <iostream>
#include <math.h> 
using namespace std;

double potencia (int a, int b) {
    return pow(a, b);
}

int leitura (int inf, int sup, char charValor){
    int valor = inf-1;

    while(valor < inf || valor > sup){
        cout << "Insira o valor de " << charValor << ": ";
        cin >> valor;
    }
    
    return valor;
}

int main () {
    int inf, sup, x, y;
    
    cout << "Insira o valor inferior: ";
    cin >> inf;
    cout << "Insira o valor superior: ";
    cin >> sup;

    x = leitura(inf, sup, 'x');
    y = leitura(inf, sup, 'y');

    cout << potencia(x, y) << endl;

    return 0;
}