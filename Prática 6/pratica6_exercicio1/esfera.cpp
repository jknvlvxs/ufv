// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#define M_PI 3.14159265358979323846  
#include "esfera.h"
#include "math.h"

Esfera::Esfera(std::string nome, std::string cor, double diametro){
    this->_nome = nome;
    this->_cor = cor;
    this->_diametro = diametro;
}

double Esfera::get_volume() {
    return 4 / 3 * M_PI * pow((_diametro / 2), 3);
}

std::string Esfera::get_nome() {
    return _nome;
}

std::string Esfera::get_cor() {
    return _cor;
}