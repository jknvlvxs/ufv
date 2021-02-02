#include <iostream>

using namespace std;

int main () {
    int notaFinal, faltaTeorica, faltaPratica, profundidade;

    cin >> notaFinal >> faltaTeorica >> faltaPratica;

    if (faltaTeorica > 15 || faltaPratica > 7 || notaFinal < 40){
        cout << "Reprovado" << endl;
    } else if (notaFinal < 60) {
        cout << "Final" << endl;
    } else {
        cout << "Aprovado" << endl;
    }
    
    return 0;
}