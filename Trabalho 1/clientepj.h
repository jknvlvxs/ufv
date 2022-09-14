#ifndef CLIENTEPJ_H
#define CLIENTEPJ_H

#include <string>

#include "cliente.h"

class ClientePJ : public Cliente{
    private:
        std::string _cnpj;

    public:
        ClientePJ(int id, std::string nome, std::string telefone, std::string endereco, std::string cnpj);

        std::string getCnpj();

        void setCnpj(std::string cnpj);
        void exibir_informacoes();
};

#endif