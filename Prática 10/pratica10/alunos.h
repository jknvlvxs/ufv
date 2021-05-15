// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef ALUNOS_H
#define ALUNOS_H

class Alunos {
    private:
        int _matricula;
        std::string _nome;
        double _nota1;
        double _nota2;
    public:
        Alunos(int matricula, std::string nome, double nota1, double nota2);
        int getMatricula();
        std::string getNome();
        double getMedia();
};

#endif