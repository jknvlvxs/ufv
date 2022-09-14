// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef ESFERA_H
#define ESFERA_H

#include <string>
#include "forma3d.h"

class Esfera : public Forma3D {
    private:
        double _diametro;
        std::string _nome;
        std::string _cor;
    public:
        Esfera(std::string nome, std::string cor, double diametro);
        virtual double get_volume();
        virtual std::string get_nome();
        virtual std::string get_cor();
};

#endif