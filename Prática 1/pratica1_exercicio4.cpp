// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

int main () {
    char str [] = "abc teste";
    int i;
    
    for(i = 0; *(str+i) != '\0'; i++);

    for(i = i - 1; i >= 0; i--) cout << *(str+i);
    
    return 0;
}