// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include <string>

class Funcionario {
    private:
        int id;
        std::string nome;
        double valor_gasto;
    public:
        Funcionario(int id, std::string nome, double valor_gasto);
        int get_id();
        std::string get_nome();
        double get_gasto();
};

#endif