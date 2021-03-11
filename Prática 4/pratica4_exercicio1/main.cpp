// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "rectangle.h"

using namespace std;

int main () {
    // criação do objeto do tipo Rectangle
    Rectangle *r = new Rectangle();
    cout << "Largura: " << r->getWidth() << " | Comprimento: " << r->getLength() << endl;

    // utilização dos metodos get e set
    r->setWidth(10.50); 
    r->setLength(7.20); 
    cout << "Largura: " << r->getWidth() << " | Comprimento: " << r->getLength() << endl;
    cout << "Perímetro: " << r->getPerimeter() << " | Área: " << r->getArea() << endl;

    // verificação da regra do get e set de só permitir numeros > 0 e < 20
    r->setWidth(20.1); 
    r->setLength(-0.1); 
    cout << "Largura: " << r->getWidth() << " | Comprimento: " << r->getLength() << endl;

    delete r;

    return 0;
}