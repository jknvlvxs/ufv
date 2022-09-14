// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "alunos.h"

void imprimeBits(unsigned int n) {
    for(int i=3;i>=0;i--) {
        if ( (n & (1<<i)) != 0)
            std::cout << 0;
        else
            std::cout << 1;
    }
}

int main () {
    int matricula = 0;
    std::string nome;
    double n1, n2;

    std::vector<Alunos> alunos;

    while(matricula != -1){
        std::cout << "Insira o número de matrícula do aluno: ";
        std::cin >> matricula;

        if(matricula != -1){
            std::cout << "Insira o nome do aluno: ";
            std::cin.ignore();
            std::getline(std::cin, nome);

            std::cout << "Insira as notas do aluno: ";
            std::cin >> n1 >> n2;

            Alunos a(matricula, nome, n1, n2);

            alunos.push_back(a);
        }
    }

    for (unsigned int i = 0; i < alunos.size(); i++){
        for (unsigned int j = 0; j < alunos.size(); j++){
            if(alunos[i].getMedia() > alunos[j].getMedia()){
                std::swap(alunos[i], alunos[j]);
            }
        }
    }

    for(Alunos as:alunos){
        imprimeBits(as.getMatricula());
        std::cout << " - " << as.getNome() << " - " << as.getMedia() << std::endl;
    }

    return 0;
}