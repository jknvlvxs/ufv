// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <string>
#include "keywords.h"

int main () {
    std::string file_name;

    std::cout << "Informe o nome do arquivo para leitura: ";
    std::cin >> file_name;

    Keywords *k = new Keywords(file_name);

    delete k;
    
    return 0;
}