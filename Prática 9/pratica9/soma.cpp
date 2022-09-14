// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "soma.h"

Soma::Soma(){}

int Soma::gerarSoma(int m, int n) {
    if(m >= n)
        return m;
    else
        return m + this->gerarSoma(m+1, n);
}