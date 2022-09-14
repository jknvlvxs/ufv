#include <iostream>
#include <cmath>
using namespace std;

int main () {

    double notas[10], soma = 0, maior = 0, menor = 999, media, desvio = 0;

    for (int i = 0; i < 10; i++){
        cin >> notas[i];
        soma += notas[i];

        if(notas[i] > maior) maior = notas[i];
        if(notas[i] < menor) menor = notas[i];
    }

    media = soma / 10;

    for (int j = 0; j < 10; j++){
        desvio += pow((notas[j] - media), 2);
    }
    
    cout << "Media das Notas: " << media << endl;
    cout << "Maior Nota: " << maior << endl;
    cout << "Menor Nota: " << menor << endl;
    cout << "Desvio Padrao: " << sqrt(desvio / 10) << endl;

    return 0;
}