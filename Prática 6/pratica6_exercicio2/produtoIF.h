// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef PRODUTOIF_H
#define PRODUTOIF_H

class ProdutoIF {
    public:
        virtual double gerarPrecoDeVenda() = 0;
};

#endif