// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <string>
#include "funcionario.h"

Funcionario::Funcionario(int id, std::string nome, double valor_gasto):
    id(id), nome(nome), valor_gasto(valor_gasto) {}

int Funcionario::get_id(){
    return id;
}

std::string Funcionario::get_nome(){
    return nome;
}

double Funcionario::get_gasto(){
    return valor_gasto;
}