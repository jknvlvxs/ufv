// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "overnightpackage.h"

OvernightPackage::OvernightPackage(std::string name, std::string address, unsigned int weight, unsigned int cost_per_kilo, double delivery_fee):
    Package(name, address, weight, cost_per_kilo), _delivery_fee(delivery_fee) {}

double OvernightPackage::calculateCost() const {
    return Package::_weight * Package::_cost_per_kilo + (Package::_cost_per_kilo * _delivery_fee);
}

