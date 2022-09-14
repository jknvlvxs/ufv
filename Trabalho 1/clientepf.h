#ifndef CLIENTEPF_H
#define CLIENTEPF_H

#include <string>

#include "cliente.h"

class ClientePF : public Cliente{
    private:
        std::string _cpf;
        std::string _dataNascimento;
        std::string _estadoCivil;

    public:
        ClientePF(int id, std::string nome, std::string telefone, std::string endereco, std::string cpf, std::string dataNascimento, std::string estadoCivil);

        std::string getCpf();
        std::string getDataNascimento();
        std::string getEstadoCivil();

        void setCpf(std::string cpf);
        void setDataNascimento(std::string dataNascimento);
        void setEstadoCivil(std::string estadoCivil);
        void exibir_informacoes();
};

#endif