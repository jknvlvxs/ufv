// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <iostream>
#include <fstream>

class Keywords {
    private:
        std::ifstream file;
    public:
        Keywords(std::string file_name);
};

#endif