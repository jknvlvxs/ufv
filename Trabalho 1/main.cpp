#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <time.h>

#include "funcionario.h"
#include "gerente.h"
#include "vendedor.h"
#include "veiculo.h"
#include "carro.h"
#include "moto.h"
#include "estoque.h"
#include "venda.h"
#include "cliente.h"
#include "clientepf.h"
#include "clientepj.h"

int input_integer(std::string input_msg, std::string error_msg) {
     std::cout << input_msg;
        int auth;
        std::cin>>auth;
        while(1) {
            if(std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << error_msg << std::endl;
                std::cout << input_msg;
                std::cin>>auth;
            }
            if(!std::cin.fail())
                break;
        }

    return auth;
}

int main() {

    Estoque estoque;
    std::vector<Funcionario> funcionarios;
    std::vector<Gerente> gerentes;
    std::vector<Vendedor> vendedores;
    std::vector<Cliente> clientes;
    std::vector<ClientePF> clientesPF;
    std::vector<ClientePJ> clientesPJ;
    std::vector<Venda> vendas;
    int veiculosIds = 1;
    
    Veiculo *v1 = new Carro(veiculosIds,"HFG-3983", 2017, "Fiat", "Argo 1.0", "Vermelho", "Flex", 39990, 4, true, true, true, "Hidráulica");
    veiculosIds++;
    Veiculo *v2 = new Carro(veiculosIds,"GWS-9104", 2014, "Chevrolet", "Onix 1.4", "Chumbo,", "Flex", 35490, 4, true, true, true, "Hidráulica");
    veiculosIds++;

    estoque.adicionar(v1, 1);
    estoque.adicionar(v2, 1);

    ClientePF *c1 = new ClientePF(1, "Ana Correa", "(31) 98888-3710", "Rua dos Cactos, 290", "123.347.601-63", "20/08/1995", "Solteiro(a)");
    ClientePF *c2 = new ClientePF(2, "Maria Correa", "(31) 97777-3710", "Rua dos Passaros, 290", "124.347.601-63", "21/08/1995", "Solteiro(a)");
    ClientePJ *c3 = new ClientePJ(3, "Márcio Correa", "(31) 96666-3710", "Rua dos Louros, 290", "456.347.601-63");
    ClientePJ *c4 = new ClientePJ(4, "Joao Correa", "(31) 95555-3710", "Rua dos Estudantes, 290", "789.347.601-63");
    clientesPF.push_back(*c1);
    clientesPF.push_back(*c2);
    clientesPJ.push_back(*c3);
    clientesPJ.push_back(*c4);
    clientes.push_back(*c1);
    clientes.push_back(*c2);
    clientes.push_back(*c3);
    clientes.push_back(*c4);
    
    Vendedor *f1 = new Vendedor(1, "João Carlos", "045.574.329-45", "(31) 95234-1485", "Av. PH Rolfs, 1023", 2200, "0415234-4");
    Gerente *f2 = new Gerente(2, "José Júlio", "123.574.329-45", "(33) 95234-1485", "Av. PH Rolfs, 1023", 2200, "0415234-4");
    vendedores.push_back(*f1);
    gerentes.push_back(*f2);
    funcionarios.push_back(*f1);
    funcionarios.push_back(*f2);

    int menu_principal;
    int menu_interno;
    int id;
    int id_v = 0;
    int tipo_funcionario = 0; // 1 - gerente || 2 - vendedor
    
    Funcionario *funcionario_sistema;

    do {
        int auth = input_integer("Informe seu ID para acessar o sistema: ", "Não foi encontrado funcionário com esse ID!");
        
        for(unsigned int i = 0; i < gerentes.size(); i++){
            if(gerentes[i].getId() == auth){
                tipo_funcionario = 1;
                funcionario_sistema = &gerentes[i];
            }
        }
        
        for(unsigned int i = 0; i < vendedores.size(); i++){
            if(vendedores[i].getId() == auth){
                tipo_funcionario = 2;
                funcionario_sistema = &vendedores[i];
            }
        }

        if(tipo_funcionario != 1 && tipo_funcionario != 2)
            std::cout << "Não foi encontrado funcionário com esse ID!" << std::endl;
    } while(tipo_funcionario != 1 && tipo_funcionario != 2);


    std::cout << std::endl << "Sistema de Concessionária" << std::endl;
    std::cout << std::endl << "Bem Vindo(a), " << (tipo_funcionario == 1 ? "gerente " : "vendedor ") << funcionario_sistema->getNome() << std::endl;
    do {
        std::cout << std::endl << "===Menu Principal===" << std::endl;
        if(tipo_funcionario == 1) std::cout << "1 - Gerenciar Funcionários" << std::endl; // TODO remover vendedor
        std::cout << "2 - Gerenciar Clientes" << std::endl;
        std::cout << "3 - Gerenciar Estoque" << std::endl;
        std::cout << "4 - Gerenciar Vendas" << std::endl;
        std::cout << "0 - Sair" << std::endl;

        menu_principal = input_integer("Insira uma opção: ", "É necessário inserir um número!");

        // Barrar vendedor de acessar gerenciar funcionários
        if(tipo_funcionario == 2 && menu_principal == 1) menu_principal = 5;

        switch (menu_principal) {
		case 1:
            do {
                std::cout << std::endl << "===Gerenciar Funcionários===" << std::endl;
                std::cout << "1 - Cadastrar Funcionário" << std::endl;
                std::cout << "2 - Listar Funcionários" << std::endl;
                std::cout << "3 - Buscar Funcionário" << std::endl;
                std::cout << "4 - Excluir Funcionário" << std::endl;
                std::cout << "0 - Voltar" << std::endl;

                menu_interno = input_integer("Insira uma opção: ", "É necessário inserir um número!");

                switch (menu_interno) {
                case 1: {
                    std::cout << std::endl << "===Cadastrar Funcionário===" << std::endl;
                    try {
                        int tipo; // 1 - gerente || 2 - vendedor
                        int id = funcionarios.size() == 0 ? 1: funcionarios[funcionarios.size()-1].getId() + 1;

                        std::string nome;
                        std::cout << "Insira o nome: ";
                        std::cin.ignore();
                        std::getline(std::cin, nome);

                        std::string cpf;
                        std::cout << "Insira o cpf: ";
                        std::cin >> cpf;

                        std::string telefone;
                        std::cout << "Insira o telefone (sem espaços): ";
                        std::cin >> telefone; 

                        std::string endereco;
                        std::cout << "Insira o endereço: ";
                        std::cin.ignore();
                        std::getline(std::cin, endereco);

                        double salario;
                        std::cout << "Insira o salário: ";
                        std::cin >> salario;

                        std::string conta; 
                        std::cout << "Insira a conta: ";
                        std::cin.ignore();
                        std::getline(std::cin, conta);

                        std::cout << "Insira o tipo (1 - Gerente, 2 - vendedor): ";
                        std::cin >> tipo;

                        if(tipo == 1){
                            Gerente f(id, nome, cpf, telefone, endereco, salario, conta);
                            gerentes.push_back(f);
                            funcionarios.push_back(f);
                        } else if (tipo == 2){
                            Vendedor f(id, nome, cpf, telefone, endereco, salario, conta);
                            vendedores.push_back(f);
                            funcionarios.push_back(f);
                        } else {
                            throw std::exception();
                        } 
                    } catch (std::exception &e){
                        std::cout << "Ocorreu um erro ao cadastrar funcionário" << e.what() << std::endl;
                    }
                }
                    break;
                case 2:
                    std::cout << std::endl << "===Listar Funcionários===" << std::endl;
                    try{
                        if (gerentes.size() > 0){
                            std::cout << std::endl << "===Gerentes===" << std::endl;
                            for(Gerente gerente:gerentes){
                                std::cout << "ID: " << gerente.getId() << std::endl;
                                std::cout << "NOME: " << gerente.getNome() << std::endl;
                                std::cout << "CPF: " << gerente.getCpf() << std::endl;
                                std::cout << "TELEFONE: " << gerente.getTelefone() << std::endl;
                                std::cout << "ENDEREÇO: " << gerente.getEndereco() << std::endl;
                                std::cout << "SALÁRIO: " << gerente.getSalario() << std::endl;
                                std::cout << "CONTA: " << gerente.getConta() << std::endl;
                                std::cout << (gerentes.size() > 1 ? "---------------------------" : "") << std::endl;
                            }
                        } else std::cout << "Não há gerentes cadastrados." << std::endl;
                        
                        if (vendedores.size() > 0){
                            std::cout << std::endl << "===Vendedores===" << std::endl;
                            for(Vendedor vendedor:vendedores){
                                std::cout << "ID: " << vendedor.getId() << std::endl;
                                std::cout << "NOME: " << vendedor.getNome() << std::endl;
                                std::cout << "CPF: " << vendedor.getCpf() << std::endl;
                                std::cout << "TELEFONE: " << vendedor.getTelefone() << std::endl;
                                std::cout << "ENDEREÇO: " << vendedor.getEndereco() << std::endl;
                                std::cout << "SALÁRIO: " << vendedor.getSalario() << std::endl;
                                std::cout << "CONTA: " << vendedor.getConta() << std::endl;
                                std::cout << (vendedores.size() > 1 ? "---------------------------" : "") << std::endl;
                            }
                        } else std::cout << "Não há vendedores cadastrados." << std::endl;
                    } catch (std::exception &e){
                        std::cout << "Ocorreu um erro ao listar funcionário: " << std::endl;
                    }
                    break;
                case 3:
                    std::cout << std::endl << "===Buscar Funcionário===" << std::endl;
                    try {
                        id = input_integer("Informe o id do Funcionário: ", "Informe um id válido!");
                        bool verifica_busca = false;

                        for(Gerente gerente:gerentes){
                            if(gerente.getId() == id){
                                verifica_busca = true;
                                std::cout << "NOME: " << gerente.getNome() << std::endl;
                                std::cout << "CPF: " << gerente.getCpf() << std::endl;
                                std::cout << "TELEFONE: " << gerente.getTelefone() << std::endl;
                                std::cout << "ENDEREÇO: " << gerente.getEndereco() << std::endl;
                                std::cout << "SALÁRIO: " << gerente.getSalario() << std::endl;
                                std::cout << "CONTA: " << gerente.getConta() << std::endl;
                            }
                        }
                        for(Vendedor vendedor:vendedores){
                            if(vendedor.getId() == id){
                                verifica_busca = true;
                                std::cout << "NOME: " << vendedor.getNome() << std::endl;
                                std::cout << "CPF: " << vendedor.getCpf() << std::endl;
                                std::cout << "TELEFONE: " << vendedor.getTelefone() << std::endl;
                                std::cout << "ENDEREÇO: " << vendedor.getEndereco() << std::endl;
                                std::cout << "SALÁRIO: " << vendedor.getSalario() << std::endl;
                                std::cout << "CONTA: " << vendedor.getConta() << std::endl;
                            }
                        }
                        if(verifica_busca == false)
                            throw std::exception();
                    } catch (std::exception &e){
                        std::cout << "Ocorreu um erro ao buscar funcionário" << std::endl;
                    }
                    break;
                case 4:
                    std::cout << std::endl << "===Excluir Funcionário===" << std::endl;
                    try{
                        id = input_integer("Informe o id do Funcionário: ", "Informe um id válido!");
                        bool verifica_delecao = false;
                            for(unsigned int i = 0; i < vendedores.size(); i++)
                                if(vendedores[i].getId() == id){
                                    vendedores.erase(vendedores.begin() + i);
                                    verifica_delecao = true;
                                }
                            for(unsigned int i = 0; i < gerentes.size(); i++)
                                if(gerentes[i].getId() == id){
                                    gerentes.erase(gerentes.begin() + i);
                                    verifica_delecao = true;
                                }
                        if(verifica_delecao == true)
                            std:: cout << "Funcionário excluído com sucesso!" << std::endl;
                        else
                            throw std::exception();
                    } catch (std::exception &e){
                        std::cout << "Ocorreu um erro ao excluir funcionário" << std::endl;
                    }
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Opção inválida!" << std::endl;
                    break;
                }
            } while (menu_interno != 0);
            break;
		case 2:
			do{
                std::cout << std::endl << "===Gerenciar Clientes===" << std::endl;
                std::cout << "1 - Cadastrar Cliente" << std::endl;
                std::cout << "2 - Listar Clientes" << std::endl;
                std::cout << "3 - Buscar Cliente" << std::endl;
                std::cout << "4 - Excluir Cliente" << std::endl;
                std::cout << "0 - Voltar" << std::endl;

                menu_interno = input_integer("Insira uma opção: ", "É necessário inserir um número!");

                switch (menu_interno) {
                case 1:{
                    try{
                        std::cout << std::endl << "===Cadastrar Cliente===" << std::endl;
                        
                        int tipoCliente; // 0 - pessoa física || 1 - pessoa jurídica
                        unsigned int idCliente = clientes.size()+1;

                        std::string nomeCliente;
                        std::cout << "Insira o nome: ";
                        std::cin.ignore();
                        std::getline(std::cin, nomeCliente);

                        std::string telefoneCliente;
                        std::cout << "Insira o telefone (sem espaços): ";
                        std::cin >> telefoneCliente; 

                        std::string enderecoCliente;
                        std::cout << "Insira o endereço: ";
                        std::cin.ignore();
                        std::getline(std::cin, enderecoCliente);

                        std::cout << "Pessoa Fisica (1) ou Pessoa Juridica (0): ";
                        std::cin >> tipoCliente;
                        if (tipoCliente == 1){
                            std::string cpfCliente; 
                            std::cout << "Insira o CPF: ";
                            std::cin.ignore();
                            std::getline(std::cin, cpfCliente);

                            std::string estadosCivis[5] = {"Solteiro(a)", "Casado(a)", "Divorciado(a)", "Viuvo(a)", "Outro"};

                            int codEstadoCivilCliente;
                            std::string estadoCivilCliente;
                            for (int i = 0; i<5; i++) std::cout << i << " - " << estadosCivis[i] << std::endl;
                            do{
                                codEstadoCivilCliente = input_integer("Insira o código do estado civil: ", "Valor inválido.");
                            } while (codEstadoCivilCliente < 0 || codEstadoCivilCliente > 4);
                            estadoCivilCliente = estadosCivis[codEstadoCivilCliente];


                            std::string dataNascimentoCliente; 
                            std::cout << "Insira a data de nascimento: ";
                            std::cin.ignore();
                            std::getline(std::cin, dataNascimentoCliente);

                            ClientePF c(idCliente, nomeCliente, telefoneCliente, enderecoCliente, cpfCliente, dataNascimentoCliente, estadoCivilCliente);
                            clientes.push_back(c);
                            clientesPF.push_back(c);
                            

                        } else if (tipoCliente==0){

                            std::string cnpjCliente; 
                            std::cout << "Insira o CNPJ: ";
                            std::cin.ignore();
                            std::getline(std::cin, cnpjCliente);

                            ClientePJ c(idCliente, nomeCliente, telefoneCliente, enderecoCliente, cnpjCliente);
                            clientes.push_back(c);
                            clientesPJ.push_back(c);
                        }  
                    }catch(std::exception &e){
                        std::cout << "Ocorreu um erro ao cadastrar o cliente." << std::endl;
                    }
                }
                    break;
                case 2:
                    std::cout << std::endl << "===Listar Clientes===" << std::endl;

                    if (clientesPF.size() > 0){

                        std::cout << std::endl << "===Clientes Pessoa Fisica===" << std::endl;

                        for(unsigned int i = 0; i < clientesPF.size(); i++){
                            
                            clientesPF[i].exibir_informacoes();
                            std::cout << (clientesPF.size() > 1 ? "---------------------------" : "") << std::endl;
                        }
                    } else std::cout << "Não há clientes pessoa física." << std::endl;
                    if (clientesPJ.size() > 0){
                        std::cout << std::endl << "===Clientes Pessoa Juridica===" << std::endl;

                        for(unsigned int i = 0; i < clientesPJ.size(); i++){
                            
                            clientesPJ[i].exibir_informacoes();
                            std::cout << (clientesPJ.size() > 1 ? "---------------------------" : "") << std::endl;
                        }
                    } else std::cout << "Não há clientes pessoa jurídica." << std::endl;
                    break;
                case 3:
                    try{
                        std::cout << std::endl << "===Buscar Cliente===" << std::endl;

                        id = input_integer("Informe o id do cliente: ", "Valor inválido.");
                        bool clienteExiste = false;
                        for (unsigned int i = 0; i<clientesPF.size(); i++){
                            if (clientesPF[i].getId() == id){
                                clientesPF[i].exibir_informacoes();
                                clienteExiste = true;
                                break;
                            }
                        }
                        for (unsigned int i = 0; i<clientesPJ.size(); i++){
                            if (clientesPJ[i].getId() == id){
                                clientesPJ[i].exibir_informacoes();
                                clienteExiste = true;
                                break;
                            }
                        }  
                        if (!clienteExiste) std::cout << "Esse cliente não existe." << std::endl;
                        break;
                    }catch(std::exception &e){
                        std::cout << "Ocorreu um erro ao buscar o cliente." << std::endl;
                    }
                case 4:
                    try{
                        std::cout << std::endl << "===Excluir Cliente===" << std::endl;
                        id = input_integer("Informe o id do cliente: ", "Valor inválido.");
                        bool clienteExiste = false;
                        for (unsigned int i = 0; i<clientesPF.size(); i++){
                            if (clientesPF[i].getId() == id){
                                clientesPF.erase(clientesPF.begin() + id);
                                clienteExiste = true;
                                break;
                            }
                        }
                        for (unsigned int i = 0; i<clientesPJ.size(); i++){
                            if (clientesPJ[i].getId() == id){
                                clientesPJ.erase(clientesPJ.begin() + id);
                                clienteExiste = true;
                                break;
                            }
                        }
                        if (clienteExiste) std:: cout << "Cliente excluído com sucesso!" << std::endl;
                        else std::cout << "Esse cliente não existe." << std::endl;
                        break;
                    }catch(std::exception &e){
                        std::cout << "Ocorreu um erro ao excluir o cliente." << std::endl;
                    }
                case 0:
                    break;
                default:
                    std::cout << "Opção inválida!" << std::endl;
                    break;
                }
            } while (menu_interno!=0);
            break;
        case 3:
			do {
                std::cout << std::endl << "===Gerenciar Estoque===" << std::endl;
                std::cout << "1 - Adicionar Veículo" << std::endl;
                std::cout << "2 - Exibir Estoque" << std::endl;
                std::cout << "3 - Buscar Veículo" << std::endl;
                std::cout << "4 - Remover Veículo" << std::endl;
                std::cout << "0 - Voltar" << std::endl;

                menu_interno = input_integer("Insira uma opção: ", "É necessário inserir um número!");

                switch (menu_interno) {
                case 1:
                    std::cout << "Carro (0) ou Moto (1)?" << std::endl;
                    int tipo;
                    std::cin >> tipo;
                    if (tipo == 0)
                    {
                        int id, ano, preco, nportas, quantidade;
                        std::string placa, marca, modelo, cor, combustivel, tdirecao;
                        bool ac,ve,te;

                        id = veiculosIds;
                        std::cout << "Quantidade: ";
                        std::cin >> quantidade;
                        std::cout << "Ano: ";
                        std::cin >> ano;
                        std::cout << "Preço: ";
                        std::cin >> preco;
                        std::cout << "Marca: ";
                        std::cin >> marca;
                        std::cout << "Modelo: ";
                        std::cin >> modelo;
                        std::cout << "Número de portas: ";
                        std::cin >> nportas;
                        std::cout << "Cor: ";
                        std::cin >> cor;
                        std::cout << "Placa: ";
                        std::cin >> placa;
                        std::cout << "Combustível: ";
                        std::cin >> combustivel;
                        std::cout << "Tipo de direção: ";
                        std::cin >> tdirecao;
                        std::cout << "Ar condicionado?(0/1): ";
                        std::cin >> ac;
                        std::cout << "Travas elétricas? (0/1): ";
                        std::cin >> te;
                        std::cout << "Vidros elétricos? (0/1): ";
                        std::cin >> ve;
                        
                        Veiculo *v = new Carro(id, placa, ano, marca, modelo, cor, combustivel, preco, nportas, ac, ve, te, tdirecao);
                        veiculosIds++;
                        estoque.adicionar(v, quantidade);
                    }
                    else
                    {
                        int id, ano, preco, cilindradas, quantidade;
                        std::string placa, marca, modelo, cor, combustivel, fd, ft, partida, injecao;

                        id = veiculosIds;
                        
                        std::cout << "Quantidade: ";
                        std::cin >> quantidade;
                        std::cout << "Ano: ";
                        std::cin >> ano;
                        std::cout << "Preço: ";
                        std::cin >> preco;
                        std::cout << "Marca: ";
                        std::cin >> marca;
                        std::cout << "Modelo: ";
                        std::cin >> modelo;
                        std::cout << "Número de cilindradas: ";
                        std::cin >> cilindradas;
                        std::cout << "Cor: ";
                        std::cin >> cor;
                        std::cout << "Placa: ";
                        std::cin >> placa;
                        std::cout << "Combustível: ";
                        std::cin >> combustivel;
                        std::cout << "Tipo Freio Dianteiro: ";
                        std::cin >> fd;
                        std::cout << "Tipo Freio Traseiro: ";
                        std::cin >> ft;
                        std::cout << "Tipo de Partida: ";
                        std::cin >> partida;
                        std::cout << "Tipo de Injeção: ";
                        std::cin >> injecao;
                        
                        Veiculo *v = new Moto(id, placa, ano, marca, modelo, cor, combustivel, preco, fd, ft, partida, injecao, cilindradas);
                        veiculosIds++;
                        estoque.adicionar(v, quantidade);
                    }

                    break;
                case 2:
                    estoque.imprimir_estoque();
                    break;
                case 3:
                    std::cout << "Procurar por ID (0) ou Modelo (1)?" << std::endl;
                    int type;
                    std::cin >> type;
                    if (type == 0)
                    {
                        int idd;
                        std::cout << "Digite o ID do veículo: ";
                        std::cin >> idd;
                        estoque.procurar(idd);
                    }
                    else
                    {
                        std::string model;
                        std::cout << "Digite o modelo do veículo: ";
                        std::cin.ignore();
                        std::getline(std::cin, model);
                        estoque.procurar(model);
                    }
                    break;
                case 4:
                    std::cout << "Digite o id do veiculo que deseja remover: ";
                    int remove;
                    std::cin >> remove;
                    estoque.remover(remove);
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Opção inválida!" << std::endl;
                    break;
                }
            } while (menu_interno != 0);
            break;
		case 4:
			do {
                std::cout << std::endl << "===Gerenciar Vendas===" << std::endl;
                std::cout << "1 - Cadastrar Venda" << std::endl;
                std::cout << "2 - Listar Vendas" << std::endl;
                std::cout << "3 - Buscar Venda" << std::endl;
                if(tipo_funcionario == 1) std::cout << "4 - Excluir Venda" << std::endl;
                std::cout << "0 - Voltar" << std::endl;

                menu_interno = input_integer("Insira uma opção: ", "É necessário inserir um número!");

                // Barrar vendedor de acessar excluir venda
                if(tipo_funcionario == 2 && menu_interno == 4) menu_interno = 5;

                switch (menu_interno) {
                case 1:
                do{
                        std::cout << "1 - Cadastrar Venda para Cliente Pessoa Física" << std::endl;
                        std::cout << "2 - Cadastrar Venda para Cliente Pessoa Jurídica" << std::endl;
                        std::cout << "0 - Cancelar" << std::endl;
                        int tp, clientid, vehicleid;
                        Veiculo *veiculo_vendido;
                        Cliente *cliente_atendido;
                        int dia, mes, ano;
                        std::string data, formapg, obs;
                        double desconto, valorfinal;
                        tp = input_integer("Insira uma opção: ", "É necessário inserir um número!");
                        if (tp == 1)
                        {
                            std::cout << "Digite o id do Cliente Pessoa Física: ";
                            std::cin >> clientid;
                            bool found = false;

                            for(unsigned int i=0; i<clientesPF.size(); i++)
                            {
                                if (clientesPF[i].getId() == clientid)
                                {
                                    cliente_atendido = new ClientePF(clientesPF[i]);
                                    found = true;
                                }
                            }
                            if (found == false)
                            {
                                std::cout << "Não existe Cliente PF com esse id." << std::endl;
                                break;
                            }
                            std::cout << "Digite o id do Veículo vendido: ";
                            std::cin >> vehicleid;
                            veiculo_vendido = estoque.buscar(vehicleid);
                            if (veiculo_vendido == nullptr)
                            {
                                std::cout << "Não existe nenhum veículo com esse id no estoque.";
                                break;
                            }
                            std::cout << "Digite o desconto: ";
                            std::cin >> desconto;
                            std::cout << "Digite a forma de pagamento utilizada: ";
                            std::cin.ignore();
                            std::getline(std::cin, formapg);
                            std::cout <<"Alguma observação?: ";
                            std::getline(std::cin, obs);

                            struct tm *data_hora;      
                            time_t segundos;
                            time(&segundos);   
                            data_hora = localtime(&segundos);
                            dia = data_hora->tm_mday;
                            mes = data_hora->tm_mon+1;
                            ano = data_hora->tm_year+1900;

                            data = (std::to_string(dia)) + '/' + (std::to_string(mes)) + '/' + (std::to_string(ano));
                            valorfinal = veiculo_vendido->getPreco() - desconto;
                            Venda venda(id_v, funcionario_sistema, cliente_atendido, veiculo_vendido, data, desconto, formapg, valorfinal, obs);
                            venda.salvar_venda();
                            vendas.push_back(venda);
                            id_v++;
                            estoque.remover(veiculo_vendido, 1);
                            break;
                        }
                        else if (tp == 2)
                        {
                            std::cout << "Digite o id do Cliente Pessoa Jurídica: ";
                            std::cin >> clientid;
                            bool found = false;

                            for(unsigned int i=0; i<clientesPJ.size(); i++)
                            {
                                if (clientesPJ[i].getId() == clientid)
                                {
                                    cliente_atendido = new ClientePJ(clientesPJ[i]);
                                    found = true;
                                }
                            }
                            if (found == false)
                            {
                                std::cout << "Não existe Cliente PJ com esse id." << std::endl;
                                break;
                            }
                            std::cout << "Digite o id do Veículo vendido: ";
                            std::cin >> vehicleid;
                            veiculo_vendido = estoque.buscar(vehicleid);
                            if (veiculo_vendido == nullptr)
                            {
                                std::cout << "Não existe nenhum veículo com esse id no estoque.";
                                break;
                            }
                            std::cout << "Digite o desconto: ";
                            std::cin >> desconto;
                            std::cout << "Digite a forma de pagamento utilizada: ";
                            std::cin.ignore();
                            std::getline(std::cin, formapg);
                            std::cout <<"Alguma observação?: ";
                            std::getline(std::cin, obs);

                            struct tm *data_hora;      
                            time_t segundos;
                            time(&segundos);   
                            data_hora = localtime(&segundos);
                            dia = data_hora->tm_mday;
                            mes = data_hora->tm_mon+1;
                            ano = data_hora->tm_year+1900;

                            data = (std::to_string(dia)) + '/' + (std::to_string(mes)) + '/' + (std::to_string(ano));
                            valorfinal = veiculo_vendido->getPreco() - desconto;
                            Venda venda(id_v, funcionario_sistema, cliente_atendido, veiculo_vendido, data, desconto, formapg, valorfinal, obs);
                            venda.salvar_venda();
                            vendas.push_back(venda);
                            id_v++;
                            estoque.remover(veiculo_vendido, 1);
                            break;
                        }
                        else{
                            break;
                        }
                    }while(true);
                    break;
                case 2:{
                    if (vendas.size() == 0)
                    {
                        std::cout << "Nenhuma venda registrada." << std::endl;
                        break;
                    }

                    for (unsigned int i=0; i<vendas.size(); i++)
                        vendas[i].imprimir_informacoes();
                }
                    break;
                case 3:{
                        std::cout << "Digite o nome do funcionário responsável, o modelo do veículo ou o nome do cliente: " << std::endl;
                        std::string entrada;
                        std::cin.ignore();
                        std::getline(std::cin, entrada);

                        bool encontrado = false;
                        for (unsigned int i=0; i<vendas.size(); i++)
                        {
                            if (entrada == vendas[i].get_funcionario()->getNome() || entrada == vendas[i].get_veiculo_vendido()->getModelo() || entrada == vendas[i].get_cliente()->getNome())
                            {
                                vendas[i].imprimir_informacoes();
                                encontrado = true;
                            }
                        }
                        if (encontrado == false)
                            std::cout << "Nenhuma venda encontrada com o termo '" << entrada << "'" << std::endl;
                }
                    break;
                case 4:{
                    std::cout << "Digite o id da venda que deseja excluir: ";
                    int num;
                    std::cin >> num;
                    for (unsigned int i=0; i<vendas.size(); i++)
                    {
                        if (num == vendas[i].get_id())
                        {
                            vendas.erase(vendas.begin()+i);
                            std::cout << "Venda excluída com sucesso." << std::endl;
                            break;
                        }
                        if (i==vendas.size()-1)
                            std::cout << "Nenhuma venda localizada com esse id." << std::endl;
                    }

                }
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Opção inválida!" << std::endl;
                    break;
                }
            } while (menu_interno != 0);
            break;
		case 0:
            std::cout << "Sistema Encerrado!" << std::endl;
			break;
		default:
			std::cout << "Opção inválida!" << std::endl;
            break;
		}
    } while (menu_principal != 0 && (tipo_funcionario == 1 || tipo_funcionario == 2));

    delete f1;
    delete f2;

    return 0;
}