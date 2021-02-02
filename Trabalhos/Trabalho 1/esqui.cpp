#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double distancia, nota1, nota2, nota3, nota4, nota5, notaDistancia;

    cin >> distancia;
    cin >> nota1 >> nota2 >> nota3 >> nota4 >> nota5;

    // gerando array para ordenar e facilitar para somar as notas intermediárias
    double notasJurados[5] = {nota1, nota2, nota3, nota4, nota5};
    double aux = 0;

    // ordanação do array
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(notasJurados[i] < notasJurados[j]){
                aux = notasJurados[i];
                notasJurados[i] = notasJurados[j];
                notasJurados[j] = aux;
            }
        }
    }

    cout << fixed << setprecision(1) << 60 + ((distancia - 120) * 1.8) + notasJurados[1] + notasJurados[2] + notasJurados[3]  << endl;
    
    return 0;
}