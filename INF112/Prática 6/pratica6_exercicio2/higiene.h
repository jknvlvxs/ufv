// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef HIGIENE_H
#define HIGIENE_H

#include "produto.h"

class Higiene : public Produto {
    public:
        Higiene(std::string codigo, std::string descricao, double preco_compra);
        virtual double gerarPrecoDeVenda();
};

#endif