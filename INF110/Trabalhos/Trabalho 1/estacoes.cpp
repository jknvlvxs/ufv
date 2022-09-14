#include <iostream>
#include <string>

using namespace std;

int main () {
    int dia, mes;
    const char *meses[12] = { "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro" };
    string estacao;

    cin >> dia >> mes;

    if (mes == 3 && dia >= 20 || mes == 4 || mes == 5 || mes == 6 && dia < 21){
        estacao = "Outono";
    } else if (mes == 6 && dia >= 21 || mes == 7 || mes == 8 || mes == 9 && dia < 23){
        estacao = "Inverno";
    } else if (mes == 9 && dia >= 23 || mes == 10 || mes == 11 || mes == 12 && dia < 22){
        estacao = "Primavera";
    } else if (mes == 12 && dia >= 22 || mes == 1 || mes == 2 || mes == 3 && dia < 20){
        estacao = "Verao";
    }

    cout << dia << " de " << meses[mes-1] << endl;
    cout << estacao << endl;
    
    return 0;
}