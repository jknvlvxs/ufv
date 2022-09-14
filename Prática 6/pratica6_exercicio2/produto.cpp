// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "produto.h"

Produto::Produto(std::string codigo, std::string descricao, double preco_compra, double percentual_lucro):
    _codigo(codigo), _descricao(descricao), _preco_compra(preco_compra), _percentual_lucro(percentual_lucro) {}

std::string Produto::get_codigo() {
    return _codigo;
}

std::string Produto::get_descricao() {
    return _descricao;
}

double Produto::get_percentual_lucro() {
    return _percentual_lucro;
}

double Produto::get_preco_compra() {
    return _preco_compra;
}