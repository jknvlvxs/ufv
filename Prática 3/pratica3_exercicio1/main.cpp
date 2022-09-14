// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "vetor.h"

using namespace std;

int main () {
    ListaVetorInteiros *vetor = new ListaVetorInteiros();
    vetor->inserir_elemento(3);
    vetor->inserir_elemento(6);
    vetor->inserir_elemento(9);
    vetor->inserir_elemento(12);
    vetor->inserir_elemento(15);
    vetor->imprimir();
    vetor->inverte();
    vetor->imprimir();
    vetor->remover_primeiro();
    vetor->imprimir();
    vetor->remover_ultimo();
    vetor->imprimir();
    vetor->inserir_elemento(18);
    vetor->inserir_elemento(21);
    vetor->imprimir();

    delete vetor;

    return 0;
}