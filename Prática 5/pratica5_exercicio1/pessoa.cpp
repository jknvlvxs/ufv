// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "pessoa.h"

Pessoa::Pessoa(std::string nome):
    _nome(nome) {}

std::string Pessoa::get_nome() const {
    return this->_nome;
}