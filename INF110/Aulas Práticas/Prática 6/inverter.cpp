#include <iostream>

using namespace std;

int main () {
    int n;
    cin >> n;
    int listaNumeros[n];

    for(int i = 0; i < n; i++){
        cin >> listaNumeros[i];
    }

    for(int i = n-1; i >= 0; i--){
        cout << listaNumeros[i];
        if(i == 0) cout << endl;
        else cout << " ";
    }
        
    return 0;
}