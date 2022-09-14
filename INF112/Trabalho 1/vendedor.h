#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <string>

#include "funcionario.h"

class Vendedor : public Funcionario {
    public:
        Vendedor(int id, std::string nome, std::string cpf, std::string telefone, std::string endereco, double salario, std::string conta);
};

#endif