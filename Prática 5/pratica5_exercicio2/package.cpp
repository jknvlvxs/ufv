// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "package.h"

Package::Package(std::string name, std::string address, unsigned int weight, unsigned int cost_per_kilo):
    _name(name), _address(address), _weight(weight), _cost_per_kilo(cost_per_kilo) {}

double Package::calculateCost() const {
    return _weight * _cost_per_kilo;
}

