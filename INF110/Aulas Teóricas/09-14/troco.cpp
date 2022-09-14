#include <iostream>

using namespace std;

int main () {
    int valorcomida, valorbebida, valorsobremesa, valorpago;

    cout << "Informe o valor da comida: ";
    cin >> valorcomida;
    cout << "Informe o valor da bebida: ";
    cin >> valorbebida;
    cout << "Informe o valor da sobremesa: ";
    cin >> valorsobremesa;
    cout << "Informe o valor pago: ";
    cin >> valorpago;

    if(valorpago > valorbebida + valorcomida + valorsobremesa) {
        cout << "O valor do troco e " << valorpago - (valorbebida + valorcomida + valorsobremesa) << endl;
    } else if (valorpago < valorbebida + valorcomida + valorsobremesa) {
        cout << "O valor pago nao e suficiente para pagar o consumo" << endl;
    } else {
        cout << "Nao havera troco pois o valor pago e identico ao valor do consumo" << endl;
    }
    
    return 0;
}