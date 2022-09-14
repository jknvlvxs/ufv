// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef FORMA_H
#define FORMA_H

#include <string>

class Forma {
    public:
        virtual std::string get_cor() = 0;
        virtual std::string get_nome() = 0;
};

#endif