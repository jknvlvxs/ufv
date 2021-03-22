// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "contapoupanca.h"

ContaPoupanca::ContaPoupanca(std::string name, std::string cpf, double current_balance, double yield):
    Conta(name, cpf, current_balance), _yield(yield) {}

double ContaPoupanca::get_saldo() {
    Conta::_current_balance += _yield;
    _yield = 0;
    return Conta::_current_balance;
}

void ContaPoupanca::muda_rendimento(double yield){
    _yield = yield;
}

