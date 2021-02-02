#include <iostream>

using namespace std;

int main () {
    int n, valorX;
    cin >> n;
    int listaNumeros[n];
    bool resultado = false;

    for(int i = 0; i < n; i++){
        cin >> listaNumeros[i];
    }

    cin >> valorX;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && listaNumeros[i] + listaNumeros[j] == valorX){
                resultado = true;
            }
        }
    }   

    cout << (resultado ? "SIM" : "NAO") << endl;
        
    return 0;
}