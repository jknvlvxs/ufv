// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "higiene.h"

Higiene::Higiene(std::string codigo, std::string descricao, double preco_compra):
    Produto(codigo, descricao, preco_compra, 30) {}

double Higiene::gerarPrecoDeVenda() {
    return _preco_compra + (_preco_compra * _percentual_lucro / 100);
}