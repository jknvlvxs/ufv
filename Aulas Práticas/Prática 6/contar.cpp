#include <iostream>

using namespace std;

int main () {
    int n, numeroCorte, contadorNumeros = 0;
    cin >> n;
    int listaNumeros[n];

    for(int i = 0; i < n; i++){
        cin >> listaNumeros[i];
    }

    cin >> numeroCorte;

    for(int i = 0; i < n; i++){
        if(listaNumeros[i] >= numeroCorte){
            contadorNumeros++;
        }
    }

    cout << contadorNumeros << endl;
        
    return 0;
}