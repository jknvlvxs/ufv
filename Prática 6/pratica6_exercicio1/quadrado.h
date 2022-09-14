// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef QUADRADO_H
#define QUADRADO_H

#include <string>
#include "forma2d.h"

class Quadrado : public Forma2D {
    private:
        std::string _nome;
        std::string _cor;
        double _aresta;
    public:
        Quadrado(std::string nome, std::string cor, double aresta);
        virtual double get_area();
        virtual double get_perimetro();
        virtual std::string get_nome();
        virtual std::string get_cor();
};

#endif