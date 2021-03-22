// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "conta.h"

Conta::Conta(std::string name, std::string cpf, double current_balance):
    _name(name), _cpf(cpf), _current_balance(current_balance) {}

double Conta::get_saldo() {
    return _current_balance;
}

void Conta::set_saldo(double current_balance) {
    _current_balance = current_balance;
}