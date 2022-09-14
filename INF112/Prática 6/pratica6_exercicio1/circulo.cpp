// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#define M_PI 3.14159265358979323846  
#include "circulo.h"
#include "math.h"

Circulo::Circulo(std::string nome, std::string cor, double diametro){
    this->_nome = nome;
    this->_cor = cor;
    this->_diametro = diametro;
}
double Circulo::get_area() {
    return M_PI * pow((_diametro / 2), 2);
}

double Circulo::get_perimetro() {
    return 2 * M_PI * (_diametro / 2);
}

std::string Circulo::get_nome() {
    return _nome;
}

std::string Circulo::get_cor() {
    return _cor;
}