#include <string>

#include "carro.h"

Carro::Carro(int id, std::string placa, int ano, std::string marca, std::string modelo, std::string cor, std::string combustivel, int preco, int numPortas, bool arCondicionado, bool vidroEletrico, bool travasEletricas, std::string tipoDirecao):
    Veiculo(id, placa, ano, marca, modelo, cor, combustivel, preco), _numPortas(numPortas), _arCondicionado(arCondicionado), _vidroEletrico(vidroEletrico), _travasEletricas(travasEletricas), _tipoDirecao(tipoDirecao) {}
 
int Carro::get_numPortas() {
    return _numPortas;
}

void Carro::set_numPortas(int numPortas) {
    _numPortas = numPortas;
}

bool Carro::get_arCondicionado() {
    return _arCondicionado;
}

void Carro::set_arCondicionado(bool arCondicionado) {
    _arCondicionado = arCondicionado;
}

bool Carro::get_vidroEletrico() {
    return _vidroEletrico;
}

void Carro::set_vidroEletrico(bool vidroEletrico) {
    _vidroEletrico = vidroEletrico;
}

bool Carro::get_travasEletricas() {
    return _travasEletricas;
}

void Carro::set_travasEletricas(bool travasEletricas) {
    _travasEletricas = travasEletricas;
}

std::string Carro::get_tipoDirecao() {
    return _tipoDirecao;
}

void Carro::set_tipoDirecao(std::string tipoDirecao) {
    _tipoDirecao = tipoDirecao;
}

void Carro::exibir_informacoes(){
    	std::cout << "------------------------------------------------------" << std::endl;
        std::cout << "Tipo: Carro" << std::endl;
		std::cout << "ID: " << Veiculo::getId() << std::endl;
		std::cout << "Placa: " << Veiculo::getPlaca() << std::endl;
		std::cout << "Ano: " << Veiculo::getAno() << std::endl;
		std::cout << "Marca: " << Veiculo::getMarca() << std::endl;
		std::cout << "Modelo: " << Veiculo::getModelo() << std::endl;
		std::cout << "Cor: " << Veiculo::getCor() << std::endl;
		std::cout << "Tipo de combustivel: " << Veiculo::getCombustivel() << std::endl;
		std::cout << "Preco: " << Veiculo::getPreco() << std::endl;
        std::cout << "Número de portas: " << this->get_numPortas() << std::endl;
        std::cout << "Ar condicionado: ";
        this->get_arCondicionado() ? std::cout << "Sim" << std::endl : std::cout << "Não" << std::endl;
        std::cout << "Vidros elétricos: ";
        this->get_vidroEletrico() ? std::cout << "Sim" << std::endl : std::cout << "Não" << std::endl;
        std::cout << "Travas elétricas: ";
        this->get_travasEletricas() ? std::cout << "Sim" << std::endl : std::cout << "Não" << std::endl;  
        std::cout << "Tipo de direção: " << this->get_tipoDirecao() << std::endl; 
		std::cout << std::endl;
}
