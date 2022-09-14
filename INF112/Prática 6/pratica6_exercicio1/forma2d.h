// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef FORMA2D_H
#define FORMA2D_H

#include <string>
#include "forma.h"

class Forma2D : public Forma {
    public:
        virtual double get_area() = 0;
        virtual double get_perimetro() = 0;
};

#endif