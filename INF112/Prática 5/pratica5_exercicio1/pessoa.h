// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef INF112_PESSOA_H
#define INF112_PESSOA_H

#include <string>

class Pessoa {
    private:
        const std::string _nome;
    public:
        Pessoa(std::string nome);
        virtual std::string get_nome() const;
};

#endif