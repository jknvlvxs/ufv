// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef VETOR_H
#define VETOR_H

class PosicoesVetor { 
    private: 
        int *_vetor;
        int _capacidade;
    public: 
        PosicoesVetor(int capacidade);
        ~PosicoesVetor();
        void inserir_elemento(int posicao, int elemento);
};

#endif