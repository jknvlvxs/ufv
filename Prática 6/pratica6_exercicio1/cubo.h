// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef CUBO_H
#define CUBO_H

#include <string>
#include "forma3d.h"

class Cubo : public Forma3D {
    private:
        double _aresta;
        std::string _nome;
        std::string _cor;
    public:
        Cubo(std::string nome, std::string cor, double aresta);
        virtual double get_volume();
        virtual std::string get_nome();
        virtual std::string get_cor();
};

#endif