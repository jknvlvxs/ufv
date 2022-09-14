#ifndef VENDA_H
#define VENDA_H

#include <string>
#include <fstream>

#include "funcionario.h"
#include "veiculo.h"
#include "cliente.h"

class Venda {
	protected:
		int _id;
		Funcionario *_funcionario_responsavel;
		Cliente *_cliente_atendido;
		Veiculo *_veiculo_vendido;
		std::string _data;
		double _desconto;
		std::string _forma_pagamento;
		double _valor_final;
		std::string _obs;
		

	public:
		Venda(int id, Funcionario *funcionario_responsavel, Cliente *cliente_atendido, Veiculo *veiculo_vendido, std::string data, double desconto, std::string forma_pagamento, double valor_final, std::string obs);

		int get_id();
		Funcionario* get_funcionario();
		Cliente* get_cliente();
		Veiculo* get_veiculo_vendido();
		std::string get_data();
		double get_desconto();
		std::string get_forma_pagamento();
		double get_valor_final();
		std::string get_obs();

		void set_funcionario(Funcionario *f);
		void set_cliente(Cliente *c);
		void set_veiculo_vendido(Veiculo *v);
		void set_data(std::string d);
		void set_desconto(double desc);
		void set_forma_pagamento(std::string forma_pg);
		void set_valor_final(double valor);
		void set_obs(std::string o);
		void imprimir_informacoes();
		void salvar_venda();
};

#endif