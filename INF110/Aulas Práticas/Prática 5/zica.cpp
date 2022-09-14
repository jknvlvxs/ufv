#include <iostream>

using namespace std;

int main () {
    long long int populacaoInicial;
    int taxaReproducao, hora = 0;

    cin >> populacaoInicial >> taxaReproducao;

    while(populacaoInicial < 1000000000){
        populacaoInicial = populacaoInicial + populacaoInicial * taxaReproducao;
        hora++;
    }

    cout << hora << endl;
        
    return 0;
}