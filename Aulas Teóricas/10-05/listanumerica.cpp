#include <iostream>

using namespace std;

int main () {

    int n;
    cin >> n;
    int numeros[n];
    bool verificador;

    for (int i = 0; i < n; i++){
        cin >> numeros[i];
    }

    for (int i = 1; i <= n; i++){
        verificador = false;
        
        for (int j = 0; j < n; j++){
            if(i == numeros[j]){
                verificador = true;
            }
        }

        if(!verificador){
            cout << i << " ";
        }
    }

    return 0;
}