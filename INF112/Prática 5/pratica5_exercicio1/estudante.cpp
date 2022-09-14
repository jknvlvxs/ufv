// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "estudante.h"

Estudante::Estudante(std::string nome, int matricula, Turma turma):
    Pessoa(nome), _matricula(matricula), _turma(turma) {}

int Estudante::get_matricula() const {
    return this->_matricula;
}

Turma Estudante::get_turma() {
    return this->_turma;
}

void Estudante::set_turma(Turma turma) {
    _turma = turma;
}