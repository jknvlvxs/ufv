// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "conta.h"

class ContaCorrente : public Conta {
    public:
        ContaCorrente(std::string name, std::string cpf, double current_balance);
};

#endif