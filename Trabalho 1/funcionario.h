#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>

class Funcionario {
    protected:
        int _id;
        std::string _nome;
        std::string _cpf;
        std::string _telefone;
        std::string _endereco;
        double _salario;
        std::string _conta;
    public:
        Funcionario(int id, std::string nome, std::string cpf, std::string telefone, std::string endereco, double salario, std::string conta);
        
        int getId();
        std::string getNome();
        std::string getCpf();
        std::string getTelefone();
        std::string getEndereco();
        double getSalario();
        std::string getConta();
        
        void setNome(std::string nome);
        void setCpf(std::string cpf);
        void setTelefone(std::string telefone);
        void setEndereco(std::string endereco);
        void setSalario(double salario);
        void setConta(std::string conta);

};

#endif