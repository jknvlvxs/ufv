// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

int calculaTamanhoString1(char *str){
    int i;
    for(i = 0; str[i] != '\0'; i++);
    return i;
}

int calculaTamanhoString2(char *str){
    int i;
    for(i = 0; *(str+i) != '\0'; i++);
    return i;
}

int calculaTamanhoString3(char *str){
    char *i;
    for (i = str; *(i) != '\0'; i += sizeof(char));
    return i-str;
}

int main () {
    char str [51];
    cout << "Digite alguma string ... ( com ate 50 caracteres ):";
    cin.getline (str, 50) ;
    cout << "Tamanhos calculados :" << endl ;
    cout << calculaTamanhoString1(str) << " " << calculaTamanhoString2(str) << " " << calculaTamanhoString3(str) ;
    cout << endl ;
    return 0;
}