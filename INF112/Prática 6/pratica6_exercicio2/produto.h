// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef PRODUTO_H
#define PRODUTO_H

#include "produtoIF.h"
#include <string>

class Produto: public ProdutoIF {
    protected:
        std::string _codigo;
        std::string _descricao;
        double _preco_compra;
        double _percentual_lucro;
    public:
        Produto(std::string codigo, std::string descricao, double preco_compra, double percentual_lucro);
        virtual double gerarPrecoDeVenda() = 0;
        std::string get_codigo();
        std::string get_descricao();
        virtual double get_preco_compra();
        double get_percentual_lucro();
};

#endif