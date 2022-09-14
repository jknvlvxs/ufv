#include <iostream>
#include <string>

#include "clientepf.h"

ClientePF::ClientePF(int id, std::string nome, std::string telefone, std::string endereco, std::string cpf, std::string dataNascimento, std::string estadoCivil) :
    Cliente(id, nome, telefone, endereco), _cpf(cpf), _dataNascimento(dataNascimento), _estadoCivil(estadoCivil) {}


std::string ClientePF::getCpf(){
    return _cpf;
}

void ClientePF::setCpf(std::string cpf){
    _cpf = cpf;
}

std::string ClientePF::getDataNascimento(){
    return _dataNascimento;
}

void ClientePF::setDataNascimento(std::string dataNascimento){
    _dataNascimento = dataNascimento;
}

std::string ClientePF::getEstadoCivil(){
    return _estadoCivil;
}

void ClientePF::setEstadoCivil(std::string estadoCivil){
    _estadoCivil = estadoCivil;
}

void ClientePF::exibir_informacoes(){
    std::cout << "ID: " << getId() << std::endl;
    std::cout << "NOME: " << getNome() << std::endl;
    std::cout << "CPF: " << getCpf() << std::endl;
    std::cout << "TELEFONE: " << getTelefone() << std::endl;
    std::cout << "ENDEREÇO: " << getEndereco() << std::endl;
    std::cout << "DATA DE NASCIMENTO: " << getDataNascimento() << std::endl;
    std::cout << "ESTADO CIVIL: " << getEstadoCivil() << std::endl;
}
