// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

void preencheAleatorios(int n, int *arranjo){
    for(int i = 0; i < n; i++)
        arranjo[i] = rand() % 10 + 1;
}

void imprime(int n, int *arranjo){
    for(int i = 0; i < n; i++){
        cout << arranjo[i];
        if(i < n-1) cout << ", ";
        else cout << endl;
    }
}

void contaParImpar(int *arranjoa, int *arranjob, int n, int &contPar, int &contImpar) {
    for(int i = 0; i < n; i++){
        if((arranjoa[i] + arranjob[i]) % 2 == 0 )
            contPar++;
        else
            contImpar++;
    }
}


int main () {
    int n = 1, contPar, contImpar;
    int *a, *b;

    while (n > 0){
        contPar = 0;
        contImpar = 0;

        cout << "Digite a quantidade de jogadas a simular: ";
        cin >> n;

        if(n > 0){
            a = (int *) malloc (n * sizeof(int));
            b = (int *) malloc (n * sizeof(int));

            preencheAleatorios(n, a);
            preencheAleatorios(n, b);
            imprime(n, a);
            imprime(n, b);
            contaParImpar(a, b, n, contPar, contImpar);
            cout << "Par: " << contPar << endl << "Impar: " << contImpar << endl;

            free(a);
            free(b);
        }
    }
    return 0;
}