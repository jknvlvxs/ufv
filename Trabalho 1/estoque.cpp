#include "estoque.h"

Estoque::Estoque () {
}

int Estoque::getNumVeiculos(){
	return _veiculos.size();
}

void Estoque::adicionar(Veiculo *veiculo, int qntd) {
	Veiculos_Quantidade vehicle;
	vehicle.v = veiculo;
	vehicle.quantidade = qntd;

	_veiculos.push_back(vehicle);
	std::cout << "Veículo(s) adicionado(s) com sucesso ao estoque." << std::endl;
}

void Estoque::remover(Veiculo *veiculo, int qntd) {
	for (unsigned int i=0; i<_veiculos.size(); i++)
	{
		if (_veiculos[i].v->getId() == veiculo->getId())
		{
			if(_veiculos[i].quantidade <= qntd)
				_veiculos.erase(_veiculos.begin()+i);
			else
				_veiculos[i].quantidade -= qntd;

			std::cout << "Veículo(s) removido(s) com sucesso do estoque." << std::endl;

			break;
		}
		if (i==_veiculos.size()-1)
			std::cout << "Este veículo não está no estoque." << std::endl;
	}
}

void Estoque::remover(int id) {
	for (unsigned int i=0; i<_veiculos.size(); i++)
	{
		if (_veiculos[i].v->getId() == id)
		{
			_veiculos.erase(_veiculos.begin()+i);
			std::cout << "Veiculo(s) removido(s) com sucesso do estoque." << std::endl;
			break;
		}
		if (i==_veiculos.size()-1)
			std::cout << "Não existe(m) veículo(s) com esse id no estoque." << std::endl;
	}
}

void Estoque::procurar(int id){
	for (unsigned int i=0; i<_veiculos.size(); i++)
	{
		if (_veiculos[i].v->getId() == id)
		{
			_veiculos[i].v->exibir_informacoes();
			std::cout << "Quantidade em estoque: " << _veiculos[i].quantidade << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
			break;
		}
		if (i==_veiculos.size()-1)
			std::cout << "Não existe(m) veículo(s) com esse id no estoque." << std::endl;
	}
}

void Estoque::procurar(std::string modelo){
	bool tem = false;

	for (unsigned int i=0; i<_veiculos.size(); i++)
	{
		if (_veiculos[i].v->getModelo() == modelo)
		{
			_veiculos[i].v->exibir_informacoes();
			std::cout << "Quantidade em estoque: " << _veiculos[i].quantidade << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
			tem = true;
		}
		if (i==_veiculos.size()-1 && tem == false)
			std::cout << "Nenhum veículo localizado com o modelo '" << modelo << "'." << std::endl;
	}
}

Veiculo* Estoque::buscar(int id){
	for (unsigned int i=0; i<_veiculos.size(); i++)
	{
		if (_veiculos[i].v->getId() == id)
		{
			return _veiculos[i].v;
		}
	}

	return nullptr;
}

void Estoque::imprimir_estoque() {
	if (_veiculos.size() == 0)
		std::cout << "Estoque vazio." << std::endl;
	else
	{
		for (unsigned int i=0; i<_veiculos.size(); i++)
		{
			_veiculos[i].v->exibir_informacoes();
			std::cout << "Quantidade em estoque: " << _veiculos[i].quantidade << std::endl;
			std::cout << "------------------------------------------------------" << std::endl;
		}
	}
}
