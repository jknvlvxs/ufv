#include "funcionario.h"

Funcionario::Funcionario(int id, std::string nome, std::string cpf, std::string telefone, std::string endereco, double salario, std::string conta):
    _id(id), _nome(nome), _cpf(cpf), _telefone(telefone), _endereco(endereco), _salario(salario), _conta(conta) {}

int Funcionario::getId() {
    return _id;
}

std::string Funcionario::getNome() {
    return _nome;
}

void Funcionario::setNome(std::string nome) {
    _nome = nome;
}

std::string Funcionario::getCpf() {
    return _cpf;
}

void Funcionario::setCpf(std::string cpf) {
    _cpf = cpf;
}

std::string Funcionario::getTelefone() {
    return _telefone;
}

void Funcionario::setTelefone(std::string telefone) {
    _telefone = telefone;
}

std::string Funcionario::getEndereco() {
    return _endereco;
}

void Funcionario::setEndereco(std::string endereco) {
    _endereco = endereco;
}

double Funcionario::getSalario() {
    return _salario;
}

void Funcionario::setSalario(double salario) {
    _salario = salario;
}

std::string Funcionario::getConta() {
    return _conta;
}

void Funcionario::setConta(std::string conta) {
    _conta = conta;
}

