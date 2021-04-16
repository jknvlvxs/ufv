// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "medicamento.h"

Medicamento::Medicamento(std::string codigo, std::string descricao, double preco_compra, double percentual_lucro, double valor_desconto_lab):
    Produto(codigo, descricao, preco_compra, percentual_lucro), _valor_desconto_lab(valor_desconto_lab) {}

double Medicamento::gerarPrecoDeVenda() {
    return _preco_compra + (_preco_compra * _percentual_lucro / 100) - _valor_desconto_lab;
}

double Medicamento::get_preco_compra() {
    return _preco_compra - _valor_desconto_lab;
}