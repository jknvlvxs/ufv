#include <iostream>

using namespace std;

int main() {
    int pratos, ingredientes;
    cin >> pratos >> ingredientes;
    int matriz[pratos][ingredientes];
    int precos[ingredientes];
    int preco;

    for(int i = 0; i < pratos; i++){
        for(int j = 0; j < ingredientes; j++){
            cin >> matriz[i][j];
        }
    }

    for(int j = 0; j < ingredientes; j++){
        cin >> precos[j];
    }

    for(int i = 0; i < pratos; i++){
        preco = 0;
        for(int j = 0; j < ingredientes; j++){
            preco += matriz[i][j] * precos[j];
        }
        cout << preco;
        if(i < pratos-1)
            cout << " ";
    }

    cout << endl;

    return 0;
}