// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "turma.h"

Turma::Turma(std::string codigo, int ano):
    _codigo(codigo), _ano(ano) {}

std::string Turma::get_codigo() {
    return this->_codigo;
}

int Turma::get_ano() {
    return this->_ano;
}

void Turma::set_codigo(std::string codigo) {
    _codigo = codigo;
}

void Turma::set_ano(int ano) {
    _ano = ano;
}