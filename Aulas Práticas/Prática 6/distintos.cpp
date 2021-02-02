#include <iostream>

using namespace std;

int main () {
    int n, qtdDistintos;
    cin >> n;
    int listaNumeros[n];
    bool distinto;

    qtdDistintos = n;

    for(int i = 0; i < n; i++){
        cin >> listaNumeros[i];
    }

    for(int i = 0; i < n; i++){
        distinto = false;
        for(int j = 0; j < n; j++){
            if(i < j && listaNumeros[i] == listaNumeros[j]){
                distinto = true;
            }
        }
        if(distinto) qtdDistintos--;
    } 

    cout << qtdDistintos << endl;
        
    return 0;
}