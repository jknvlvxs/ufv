// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "power.h"

Power::Power(){}

int Power::gerarPotencia(int k, int n) {
    if(n == 0)
        return 1;
    else if(n == 1)
        return k;
    else
        return k * this->gerarPotencia(k, n-1);
}