#ifndef MOTO_H
#define MOTO_H

#include <string>
#include <iostream>
#include "veiculo.h"
class Moto : public Veiculo {
	protected:
        std::string _tipoFreioDianteiro;
        std::string _tipoFreioTraseiro;
        std::string _tipoPartida;
        std::string _injecaoEletCarb;
        int _numCilindradas;
    public:
        Moto(int id, std::string placa, int ano, std::string marca, std::string modelo, std::string cor, std::string combustivel, int preco, std::string tipoFreioDianteiro, std::string tipoFreioTraseiro, std::string tipoPartida, std::string injecaoEletCarb, int numCilindradas);

        std::string getTipoFreioDianteiro();
        std::string getTipoFreioTraseiro();
        std::string getTipoPartida();
        std::string getInjecaoEletCarb();
        int getNumCilindradas();

        void setTipoFreioDianteiro(std::string tipoFreioDianteiro);
        void setTipoFreioTraseiro(std::string tipoFreioTraseiro);
        void setTipoPartida(std::string tipoPartida);
        void setInjecaoEletCarb(std::string injecaoEletCarb);
        void setNumCilindradas(int numCilindradas);
        virtual void exibir_informacoes() override;
};

#endif