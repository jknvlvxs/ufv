#include <iostream>
#include <string>

#include "cliente.h"

Cliente::Cliente(int id, std::string nome, std::string telefone, std::string endereco) :
    _id(id), _nome(nome), _telefone(telefone), _endereco(endereco) {}

int Cliente::getId(){
    return _id;
}

void Cliente::setId(int id){
    _id = id;
}

std::string Cliente::getNome(){
    return _nome;
}

void Cliente::setNome(std::string nome){
    _nome = nome;
}

std::string Cliente::getTelefone(){
    return _telefone;
}

void Cliente::setTelefone(std::string telefone){
    _telefone = telefone;
}

std::string Cliente::getEndereco(){
    return _endereco;
}

void Cliente::setEndereco(std::string endereco){
    _endereco = endereco;
}