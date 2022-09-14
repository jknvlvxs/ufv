// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {
    private:
        const double _delivery_fee;
    public:
        TwoDayPackage(std::string name, std::string address, unsigned int weight, unsigned int cost_per_kilo, double delivery_fee);
        virtual double calculateCost() const override;

};

#endif