#include "venda.h"

Venda::Venda(int id, Funcionario *funcionario_responsavel, Cliente *cliente_atendido, Veiculo *veiculo_vendido, std::string data, double desconto, std::string forma_pagamento, double valor_final, std::string obs):
_id(id),_funcionario_responsavel(funcionario_responsavel), _cliente_atendido(cliente_atendido), _veiculo_vendido(veiculo_vendido), _data(data), _desconto(desconto), _forma_pagamento(forma_pagamento), _valor_final(valor_final), _obs(obs){}

int Venda::get_id(){
	return _id;
}
Funcionario* Venda::get_funcionario(){
	return _funcionario_responsavel;
}

Cliente* Venda::get_cliente(){
	return _cliente_atendido;
}

Veiculo* Venda::get_veiculo_vendido(){
	return _veiculo_vendido;
}

std::string Venda::get_data(){
	return _data;
}

double Venda::get_desconto(){
	return _desconto;
}

std::string Venda::get_forma_pagamento(){
	return _forma_pagamento;
}

double Venda::get_valor_final(){
	return _valor_final;
}

std::string Venda::get_obs(){
	return _obs;
}

void Venda::set_funcionario(Funcionario *f){
	_funcionario_responsavel = f;
}

void Venda::set_cliente(Cliente *c){
	_cliente_atendido = c;
}

void Venda::set_veiculo_vendido(Veiculo *v){
	_veiculo_vendido = v;
}

void Venda::set_data(std::string d){
	_data = d;
}

void Venda::set_desconto(double desc){
	_desconto = desc;
}

void Venda::set_forma_pagamento(std::string forma_pg){
	_forma_pagamento = forma_pg;
}

void Venda::set_valor_final(double valor){
	_valor_final = valor;
}

void Venda::set_obs(std::string o){
	_obs = o;
}

void Venda::imprimir_informacoes(){
	std::cout << "ID: " << this->get_id() << '\n';
	std::cout << "Cliente: " << this->get_cliente()->getNome() << '\n';
    std::cout << "Funcionário responsável: " << this->get_funcionario()->getNome() << '\n';
    std::cout << "Marca e modelo do veículo: " << this->get_veiculo_vendido()->getMarca() << " " << this->get_veiculo_vendido()->getModelo() << '\n';
    std::cout << "Valor final: " << this->get_valor_final() << '\n';
    std::cout << "Forma de pagamento: " << this->get_forma_pagamento() << '\n';
    std::cout << "Data: " << this->get_data() << '\n';
    std::cout << "Observações: " << this->get_obs() << '\n';
    std::cout << "--------------------------------------------" << '\n';
}

void Venda::salvar_venda(){
	std::ofstream _vendas;
	_vendas.open("relatorio de vendas.txt", std::ios::app);

	if(!_vendas.is_open())
	{
		std::cout << "Erro ao salvar venda." << std::endl;
		return;
	}
	_vendas << "ID: " << this->get_id() << '\n';
	_vendas << "Cliente: " << this->get_cliente()->getNome() << '\n';
	_vendas << "Funcionário responsável: " << this->get_funcionario()->getNome() << '\n';
	_vendas << "Marca e modelo do veículo: " << this->get_veiculo_vendido()->getMarca() << " " << this->get_veiculo_vendido()->getModelo() << '\n';
	_vendas << "Valor final: " << this->get_valor_final() << '\n';
	_vendas << "Forma de pagamento: " << this->get_forma_pagamento() << '\n';
	_vendas << "Data: " << this->get_data() << '\n';
	_vendas << "Observações: " << this->get_obs() << '\n';
	_vendas << "--------------------------------------------" << '\n';

	_vendas.close();

	return;
}