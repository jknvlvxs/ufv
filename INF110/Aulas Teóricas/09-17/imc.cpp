#include <iostream>
#include <cmath>

using namespace std;

int main () {
    double altura, massa;

    cout << "Informe a altura: ";
    cin >> altura;
    cout << "Informe a massa: ";
    cin >> massa;

    double imc = massa / pow(altura, 2);
    cout << "IMC: " << imc << endl;

    if(imc < 18.5) {
        cout << "Abaixo do Peso!" << endl;
    } else if (imc >= 18.5 && imc < 25) {
        cout << "Peso normal!" << endl;
    } else if (imc >= 25 && imc < 30) {
        cout << "Acima do Peso!" << endl;
    } else if (imc >= 30) {
        cout << "Obesidade!" << endl;
    }
    
    return 0;
}