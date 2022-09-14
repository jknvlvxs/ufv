// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>
#include "aquecedor.h"

using namespace std;

int main () {
    Aquecedor *a = new Aquecedor();
    cout << setprecision(2) << fixed;

    cout << a->getTemperatura() << "°C" << endl;

    a->aumentarTemperatura();
    cout << a->getTemperatura() << "°C" << endl;
    
    a->abaixarTemperatura();
    a->abaixarTemperatura();
    cout << a->getTemperatura() << "°C" << endl;

    delete a;
    
    return 0;
}