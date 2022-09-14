// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <string>
#include "forma2d.h"

class Triangulo : public Forma2D {
    private:
        double _lado_a;
        double _lado_b;
        double _lado_c;
        std::string _nome;
        std::string _cor;
    public:
        Triangulo(std::string nome, std::string cor, double lado_a, double lado_b, double lado_c);
        virtual double get_area();
        virtual double get_perimetro();
        virtual std::string get_nome();
        virtual std::string get_cor();
};

#endif