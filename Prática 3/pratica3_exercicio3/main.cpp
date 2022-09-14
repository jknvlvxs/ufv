// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "aluno.h"

using namespace std;

int main () {
    Aluno *aluno = new Aluno("José Júlio Alves Campolina", "ES102022");
    aluno->adicionarNota(100);
    aluno->adicionarNota(80);
    aluno->adicionarNota(90);
    aluno->adicionarNota(70);
    aluno->adicionarNota(60);
    aluno->adicionarNota(50);
    aluno->calcularMediaAluno();
    aluno->imprimeInformacoesAluno();

    delete aluno;

    return 0;
}