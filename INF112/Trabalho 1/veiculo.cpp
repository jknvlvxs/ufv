#include "veiculo.h"

Veiculo::Veiculo(int id, std::string placa, int ano, std::string marca, std::string modelo, std::string cor, std::string combustivel, int preco):
    _id(id), _placa(placa), _ano(ano), _marca(marca), _modelo(modelo), _cor(cor), _combustivel(combustivel), _preco(preco) {}

int Veiculo::getId() {
    return _id;
}

std::string Veiculo::getPlaca() {
    return _placa;
}

void Veiculo::setPlaca(std::string placa) {
    _placa = placa;
}

int Veiculo::getAno() {
    return _ano;
}

void Veiculo::setAno(int ano) {
    _ano = ano;
}

std::string Veiculo::getMarca() {
    return _marca;
}

void Veiculo::setMarca(std::string marca) {
    _marca = marca;
}

std::string Veiculo::getModelo() {
    return _modelo;
}

void Veiculo::setModelo(std::string modelo) {
    _modelo = modelo;
}

std::string Veiculo::getCor() {
    return _cor;
}

void Veiculo::setCor(std::string cor) {
    _cor = cor;
}

std::string Veiculo::getCombustivel() {
    return _combustivel;
}

void Veiculo::setCombustivel(std::string combustivel) {
    _combustivel = combustivel;
}

int Veiculo::getPreco() {
    return _preco;
}

void Veiculo::setPreco(int preco) {
    _preco = preco;
}