// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "posicoesvetor.h"
#include "invalidpositionexception.h"

PosicoesVetor::PosicoesVetor(int capacidade) {
    _vetor = new int[capacidade]();
    _capacidade = capacidade;
}

void PosicoesVetor::inserir_elemento(int posicao, int elemento) {
    if(posicao < 0 || posicao >= _capacidade) throw InvalidPositionException();

    _vetor[posicao] = elemento;
}

PosicoesVetor::~PosicoesVetor() {
    delete[] _vetor;
}