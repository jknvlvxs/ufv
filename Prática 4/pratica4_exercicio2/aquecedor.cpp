// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "aquecedor.h"

Aquecedor::Aquecedor() {
    _temperatura = 20.00;
}

double Aquecedor::getTemperatura()  {
    return _temperatura;
}

void Aquecedor::aumentarTemperatura(){
    _temperatura += 5;
}

void Aquecedor::abaixarTemperatura(){
    _temperatura -= 5;
}

Aquecedor::~Aquecedor() {

}