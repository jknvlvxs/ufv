// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef SOMA_H
#define SOMA_H

#include <iostream>

class ExcecaoSoma {
    private:
        int _valor; // x
        int _valor_somado = 0; // soma de n
        int _quantidade_somados = 0;
    public:
        ExcecaoSoma();
        void setValor(int x);
        void inserir_numero(int numero);
        int getValorSomado();
        int getQuantidadeSomados();
        double getMedia();
};

#endif