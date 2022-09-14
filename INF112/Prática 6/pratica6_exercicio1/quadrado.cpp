// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "quadrado.h"

Quadrado::Quadrado(std::string nome, std::string cor, double aresta) {
    this->_nome = nome;
    this->_cor = cor;
    this->_aresta = aresta;
}

double Quadrado::get_area() {
    return _aresta * _aresta;
}

double Quadrado::get_perimetro() {
    return 4 * _aresta;
}

std::string Quadrado::get_nome() {
    return _nome;
}

std::string Quadrado::get_cor() {
    return _cor;
}