#include <iostream>
#include <string>

using namespace std;

int main () {
    double preco, valordesconto;
    string desconto;

    cout << "Informe o preco do produto: ";
    cin >> preco;
    cout << "Possui algum desconto? ";
    cin >> desconto;

    if(desconto.compare("S") == 0){
        cout << "Valor do desconto: ";
        cin >> valordesconto;
    }

    cout << "Preco Final do Produto: " << (valordesconto > 0 ? preco - preco * valordesconto / 100  : preco)  << endl;
    
    return 0;
}