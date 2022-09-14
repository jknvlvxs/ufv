// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "empresa.h"
#include "funcionario.h"

int main () {
    Empresa *e = new Empresa("funcionarios.txt", "relatorio.txt");

    delete e;
    
    return 0;
}