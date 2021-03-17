// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef INF112_ESTUDANTE_H
#define INF112_ESTUDANTE_H

#include "pessoa.h"
#include "turma.h"

class Estudante : public Pessoa {
    private:
        const int _matricula;
        Turma _turma;
    public:
        Estudante(std::string nome, int matricula, Turma turma);
        int get_matricula() const;
        Turma get_turma();
        void set_turma(Turma turma);
};

#endif