// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef INF112_TURMA_H
#define INF112_TURMA_H

#include <string>

class Turma {
    private:
        std::string _codigo;
        int _ano;
    public:
        Turma(std::string codigo, int ano);
        std::string get_codigo();
        void set_codigo(std::string codigo);
        int get_ano();
        void set_ano(int ano);
};

#endif