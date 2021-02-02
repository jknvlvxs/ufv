#include <iostream>
using namespace std;

int main () {

    double prova1[10], prova2[10];

    cout << "Notas da Prova 1: ";
    for (int i = 0; i < 10; i++){
        cin >> prova1[i];
    }

    cout << "Notas da Prova 2: ";
    for (int i = 0; i < 10; i++){
        cin >> prova2[i];
    } 

    cout << "Media das Notas: ";
    for (int i = 0; i < 10; i++){
        cout << (prova1[i] + prova2[i]) / 2 << " ";
    } 

    return 0;
}