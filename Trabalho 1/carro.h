#ifndef CARRO_H
#define CARRO_H

#include <string>

#include "veiculo.h"
#include <iostream>

class Carro : public Veiculo {
	protected:
        int _numPortas;
        bool _arCondicionado;
        bool _vidroEletrico;
        bool _travasEletricas;
        std::string _tipoDirecao;
        
    public:
        Carro(int id, std::string placa, int ano, std::string marca, std::string modelo, std::string cor, std::string combustivel, int preco, int numPortas, bool arCondicionado, bool vidroEletrico, bool travasEletricas, std::string tipoDirecao);

        int get_numPortas();
        bool get_arCondicionado();
        bool get_vidroEletrico();
        bool get_travasEletricas();
        std::string get_tipoDirecao();
        
        void set_numPortas(int numPortas);
        void set_arCondicionado(bool arCondicionado);
        void set_vidroEletrico(bool vidroEletrico);
        void set_travasEletricas(bool travasEletricas);
        void set_tipoDirecao(std::string tipoDirecao);
        virtual void exibir_informacoes() override;
};

#endif