// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "alunos.h"

Alunos::Alunos(int matricula, std::string nome, double nota1, double nota2): 
    _matricula(matricula), _nome(nome), _nota1(nota1), _nota2(nota2) {}

int Alunos::getMatricula(){
    return _matricula;
}

std::string Alunos::getNome(){
    return _nome;
}

double Alunos::getMedia(){
    return (_nota1 + _nota2) / 2;
}