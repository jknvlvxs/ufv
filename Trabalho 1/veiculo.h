#ifndef VEICULO_H
#define VEICULO_H

#include <string>
#include <iostream>

class Veiculo {
    protected:
        int _id;
        std::string _placa;
        int _ano;
        std::string _marca;
        std::string _modelo;
        std::string _cor;
        std::string _combustivel;
        int _preco;

    public:
        Veiculo(int id, std::string placa, int ano, std::string marca, std::string modelo, std::string cor, std::string combustivel, int preco);
        virtual ~Veiculo() {};

        int getId();
        std::string getPlaca();
        int getAno();
        std::string getMarca();
        std::string getModelo();
        std::string getCor();
        std::string getCombustivel();
        int getPreco();

        void setPlaca(std::string placa);
        void setAno(int ano);
        void setMarca(std::string marca);
        void setModelo(std::string modelo);
        void setCor(std::string cor);
        void setCombustivel(std::string combustivel);
        void setPreco(int preco);
        virtual void exibir_informacoes()=0;
};

#endif