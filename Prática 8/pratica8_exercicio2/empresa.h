// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include <fstream>
#include <vector>
#include "funcionario.h"

class Empresa {
    private:
        std::ifstream fin;
        std::ofstream fout;
        std::vector<Funcionario> funcionarios;
        double gasto_total;
    public:
        Empresa(std::string fin_name, std::string fout_name);
};

#endif