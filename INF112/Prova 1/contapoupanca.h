// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "conta.h"

class ContaPoupanca : public Conta {
    private:
        double _yield; // rendimento
    public:
        ContaPoupanca(std::string name, std::string cpf, double current_balance, double yield);
        double get_saldo() override;
        void muda_rendimento(double yield);
};

#endif