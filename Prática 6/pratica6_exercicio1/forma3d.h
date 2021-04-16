// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef FORMA3D_H
#define FORMA3D_H

#include <string>
#include "forma.h"

class Forma3D : public Forma {
    public:
        virtual double get_volume() = 0;
};

#endif