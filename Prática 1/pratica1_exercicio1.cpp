// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

void leiaInteiros(int a, int b) {
    cout << "Informe dois numeros inteiros: ";
    cin >> a >> b;
}

void leiaInteiros(int *a, int *b) {
    cout << "Informe dois numeros inteiros: ";
    cin >> *a >> *b;
}

int main () {
    int a = 0, b = 0;

    leiaInteiros(a, b);
    cout << a << " " << b << endl;

    leiaInteiros(&a, &b);
    cout << a << " " << b << endl;
    
    return 0;
}