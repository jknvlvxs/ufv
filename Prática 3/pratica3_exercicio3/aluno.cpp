// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "aluno.h"
#include <string>

Aluno::Aluno(std::string nome, std::string matricula) {
    _nome = nome;
    _matricula = matricula;
    _notas = new int[3]();
    _capacidade = 3;
    _num_materias = 0;
    _media_notas = 0;
}

void Aluno::adicionarNota(int nota) {
    if (_num_materias == _capacidade) {
        int *new_data = new int[_capacidade * 2];

        for (int i = 0; i < _num_materias; i++)
            new_data[i] = _notas[i];

        delete[] _notas;
        _notas = new_data;
        _capacidade = _capacidade * 2;
    }

    _notas[_num_materias] = nota;
    _num_materias++;
}

void Aluno::calcularMediaAluno() {
    int soma = 0;
    for (int i = 0; i < _num_materias; i++)
        soma += _notas[i];
    _media_notas = soma / _num_materias;
}

void Aluno::imprimeInformacoesAluno(){
    std::cout << "Nome: " << _nome <<  std::endl;
    std::cout << "Matrícula: " << _matricula <<  std::endl;
    std::cout << "Média das Notas: " << _media_notas <<  std::endl;
    std::cout << "Notas: ";
    for (int i = 0; i < _num_materias; i++)
        std::cout << _notas[i] << " ";
    std::cout << std::endl;
}

Aluno::~Aluno() {
    delete[] _notas;
}