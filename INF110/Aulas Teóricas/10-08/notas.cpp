#include <iostream>
#include <cmath>
using namespace std;

int main () {

    int notas[5][3];
    double soma;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cin >> notas[i][j];
        }   
    }

    for(int i = 0; i < 5; i++){
        cout << "Aluno " << i+1 << " - " << notas[i][0] << " " << notas[i][1] << " " << notas[i][2] << " " << " - Total: " << notas[i][0] + notas[i][1] + notas[i][2] << endl;
    }

    cout << "Media das provas: ";
    for(int i = 0; i < 3; i++){
        soma = 0;
        for(int j = 0; j < 5; j++){
            soma += notas[j][i];
        }
        cout << soma / 5 << " ";
    }


    return 0;
}