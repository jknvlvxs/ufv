#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <iostream>
#include <vector>

#include "veiculo.h"

struct Veiculos_Quantidade{
	Veiculo *v;
	int quantidade;
};

class Estoque {
protected:
	std::vector<Veiculos_Quantidade> _veiculos;

public:
	Estoque();
	
	void adicionar(Veiculo *veiculo, int quantidade);
	void remover(Veiculo *veiculo, int quantidade);
	void remover(int id);
	void imprimir_estoque();
	void procurar(int id);
	void procurar(std::string modelo);
	Veiculo* buscar(int id);
	int getNumVeiculos();
	};

#endif