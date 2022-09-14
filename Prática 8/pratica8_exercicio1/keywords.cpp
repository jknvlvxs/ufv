// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include "keywords.h"

Keywords::Keywords(std::string file_name) {
    file.open(file_name);
    std::string buffer;
    getline(file, buffer);
    char *palavra = strtok ((char*)buffer.c_str()," ,.-");

    std::vector<char*> armazenador;
    std::vector<int> contador;
    
    while (palavra != NULL) {
        palavra = strtok (NULL, " ,.-");
        bool verificador = false;

        for (int i = 0; i < armazenador.size(); i++){
            if (palavra != NULL && strcmp(armazenador[i], palavra) == 0){
                contador[i]++;  
                verificador = true;
            }
        }

        if (!verificador){
            armazenador.push_back(palavra);
            contador.push_back(1);
        }
    }

    for (int i = 0; i < armazenador.size(); i++){
        for (int j = 0; j < armazenador.size(); j++){
            if(contador[i] > contador[j]){
                int aux_int = contador[i];
                contador[i] = contador[j];
                contador[j] = aux_int;

                char *aux_char = armazenador[i];
                armazenador[i] = armazenador[j];
                armazenador[j] = aux_char;
            }
        }
    }

    std::cout << "Palavras-chave: " << armazenador[0] << ", " << armazenador[1] << ", " << armazenador[2] << std::endl;

    delete palavra;
    armazenador.clear();
}