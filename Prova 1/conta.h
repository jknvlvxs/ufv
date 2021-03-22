// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef CONTA_H
#define CONTA_H

#include <string>

class Conta {
    private:
        const std::string _name;
        const std::string _cpf;
    protected:
        double _current_balance; // saldo atual
    public:
        Conta(std::string name, std::string cpf, double current_balance);
        void set_saldo(double current_balance);
        virtual double get_saldo();
};

#endif