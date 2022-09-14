// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "estudante.h"
#include "pessoa.h"
#include "turma.h"

int main() {
    Pessoa pessoa("Julio Reis");
    Turma turma1("INF110", 2020);
    Estudante estudante("José Júlio", 102022, turma1);
    
    std::cout << "A pessoa é: " << pessoa.get_nome() << std::endl;
    std::cout << "O estudante é: " << estudante.get_nome() << std::endl;
    std::cout << "Nome: "<< estudante.get_nome() << " | Matrícula: " << estudante.get_matricula() << " | Turma: " << estudante.get_turma().get_codigo() << " | Ano: " << estudante.get_turma().get_ano() << std::endl;
    
    Turma turma2("INF112", 2021);
    estudante.set_turma(turma2);
    std::cout << "Nome: "<< estudante.get_nome() << " | Matrícula: " << estudante.get_matricula() << " | Turma: " << estudante.get_turma().get_codigo() << " | Ano: " << estudante.get_turma().get_ano() << std::endl;

    return 0;
}