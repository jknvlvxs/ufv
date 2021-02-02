#include <iostream>
#include <iomanip>
using namespace std;

int main () {

    int compras, quantidade[10];
    double preco[10], valorTotal = 0;

    cout << "Numero de produtos: ";
    cin >> compras;

    for (int i = 0; i < compras; i++){
        cout << "Preco do "<< i+1 << " item: ";
        cin >> preco[i];
        cout << "Quantidade do "<< i+1 << " item: ";
        cin >> quantidade[i];
    }

    cout << "\n--- Nota Fiscal ---" << endl;
    for (int i = 0; i < compras; i++){
        cout << "Produto " << i+1 << " | Quantidade: " << quantidade[i] << " | Valor: " << fixed << setprecision(2) << preco[i] << " | Total Produto: " << fixed << setprecision(2) << preco[i] * quantidade[i] << endl;
        valorTotal = valorTotal + preco[i] * quantidade[i];
    }

    cout << "Valor Final: " << fixed << setprecision(2) << valorTotal << endl;


    return 0;
}