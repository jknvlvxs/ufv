// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include "produto.h"

class Medicamento : public Produto {
    private:
        double _valor_desconto_lab;
    public:
        Medicamento(std::string codigo, std::string descricao, double preco_compra, double percentual_lucro, double valor_desconto_lab);
        virtual double gerarPrecoDeVenda();
        virtual double get_preco_compra();
};

#endif