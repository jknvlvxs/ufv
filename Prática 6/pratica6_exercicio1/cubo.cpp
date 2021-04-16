// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "cubo.h"
#include "math.h"

Cubo::Cubo(std::string nome, std::string cor, double aresta){
    this->_nome = nome;
    this->_cor = cor;
    this->_aresta = aresta;
}

double Cubo::get_volume() {
    return pow((_aresta * _aresta), 3);
}

std::string Cubo::get_nome() {
    return _nome;
}

std::string Cubo::get_cor() {
    return _cor;
}