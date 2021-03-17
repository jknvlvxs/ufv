// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package {
    private:
        std::string _name;
        std::string _address;
    protected:
        unsigned int _weight;
        unsigned int _cost_per_kilo;
    public:
        Package(std::string name, std::string address, unsigned int weight, unsigned int cost_per_kilo);
        virtual double calculateCost() const;
};

#endif