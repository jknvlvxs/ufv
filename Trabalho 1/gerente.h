#ifndef GERENTE_H
#define GERENTE_H

#include <string>

#include "funcionario.h"

class Gerente : public Funcionario {
    public:
        Gerente(int id, std::string nome, std::string cpf, std::string telefone, std::string endereco, double salario, std::string conta);
};

#endif