#include <iostream>
#include <string>

#include "clientepj.h"

ClientePJ::ClientePJ(int id, std::string nome, std::string telefone, std::string endereco, std::string cnpj):
  	Cliente(id, nome, telefone, endereco), _cnpj(cnpj) {}

std::string ClientePJ::getCnpj(){
    return _cnpj;
}

void ClientePJ::setCnpj(std::string cnpj){
  	_cnpj = cnpj;
}

void ClientePJ::exibir_informacoes(){
	std::cout << "ID: " << getId() << std::endl;
	std::cout << "NOME: " << getNome() << std::endl;
	std::cout << "CNPJ: " << getCnpj() << std::endl;
	std::cout << "TELEFONE: " << getTelefone() << std::endl;
	std::cout << "ENDEREÇO: " << getEndereco() << std::endl;
}