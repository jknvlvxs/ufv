// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "data.h"

using namespace std;

int main () {
    Data *data = new Data(28, 02, 2021);
    
    data->getDataBarra();
    data->getDataExtenso();
    data->getDataEmSegundos();

    delete data;

    return 0;
}