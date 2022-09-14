// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "mdc.h"

MDC::MDC(){}

int MDC::gerarMdc(int x, int y) {
    if(x % y == 0)
        return y;
    else
        return this->gerarMdc(y, (x % y));
}