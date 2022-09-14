// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "triangulo.h"
#include <cmath>

Triangulo::Triangulo(std::string nome, std::string cor, double lado_a, double lado_b, double lado_c){
    this->_nome = nome;
    this->_cor = cor;
    this->_lado_a = lado_a;
    this->_lado_b = lado_b;
    this->_lado_c = lado_c;
}

double Triangulo::get_area() {
    double semip = Triangulo::get_perimetro() / 2; // semiperimetro
    return sqrt(semip * (semip-_lado_a) * (semip-_lado_b) * (semip-_lado_c));
}

double Triangulo::get_perimetro() {
    return _lado_a + _lado_b + _lado_c;
}

std::string Triangulo::get_nome() {
    return _nome;
}

std::string Triangulo::get_cor() {
    return _cor;
}