// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef CIRCULO_H
#define CIRCULO_H

#include <string>
#include "forma2d.h"

class Circulo : public Forma2D {
    private:
        double _diametro;
        std::string _nome;
        std::string _cor;
    public:
        Circulo(std::string nome, std::string cor, double diametro);
        virtual double get_area();
        virtual double get_perimetro();
        virtual std::string get_nome();
        virtual std::string get_cor();
};

#endif