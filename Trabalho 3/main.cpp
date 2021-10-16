#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include "MyVec.h"
#include "Huffman.h"

using namespace std;


int main(int argc, char**argv) {
    string exec = argv[1];
    string path_read = argv[2];
    string path_write = argv[3];

    if(exec == "c"){

    } else if (exec == "d"){
        
    }
    
/* A seguir, crie um programa main.cpp que usa sua classe para comprimir arquivos. 
Seu programa deverá receber tres argumentos. O primeiro deverá ser “c” ou “d”. 

Se for “c”, ele deverá ler um arquivo (o caminho será o segundo argumento) e gravar
a versão comprimida dele em outro arquivo (o caminho será o terceiro argumento). 

Se o argumento for “d” ele deverá ler um arquivo comprimido (o caminho será o segundo argumento) e gravar
a versão descomprimida em outro arquivo (o caminho será o terceiro argumento).

Por exemplo, “./a.out c wikipediaBrasil.html teste.dat” deverá comprimir wikipediaBrasil.html
(gravando o arquivo comprimido em teste.dat) e “./a.out d teste.dat wikipediaBrasil.html” deverá
restaurar o arquivo (que deverá ficar IDENTICO ao original). Considerando o arquivo wikipediaBrasil.html
(disponível como exemplo), espera-se que o arquivo comprimido tenha em torno de 60% do tamanho do
arquivo original.
*/	
}