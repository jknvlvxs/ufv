// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package {
    private:
        const double _delivery_fee;
    public:
        OvernightPackage(std::string name, std::string address, unsigned int weight, unsigned int cost_per_kilo, double delivery_fee);
        virtual double calculateCost() const override;
};

#endif