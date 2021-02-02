#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char frase[100], *frase2[100];
    char * pch;
    cin.getline(frase, 100);
    // o rato roeu a roupa e o rato nao gostou da roupa

    int contador = 1;
    int contadorTipos = 0;

    for(int i = 0; frase[i] != '\0'; i++){
        if((frase[i] == ' ') || (frase[i] == '\n')){
            contador++;
        }
    }

    int count = 0;
    pch = strtok(frase, " ");
    while (pch != NULL) 
    {
        frase2[count] = pch;
        count++;
        pch = strtok(NULL, " ");
    }

    cout << *frase2 << endl;

    cout << contador << " " << count << endl;

    return 0;
}