// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>

#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"
#include "circulo.h"
#include "triangulo.h"
#include "cubo.h"
#include "esfera.h"

using namespace std;

void exibir_forma2d(Forma2D &forma){
    cout << "Nome: " << forma.get_nome() << " | Cor: " << forma.get_cor() << " | Área: " << forma.get_area() << " | Perímetro: " << forma.get_perimetro() << endl;
}

void exibir_forma3d(Forma3D &forma){
    cout << "Nome: " << forma.get_nome() << " | Cor: " << forma.get_cor() << " | Volume: " << forma.get_volume() << endl;
}

int main(void) {
    cout << setprecision(2) << fixed;

    Forma2D *q = new Quadrado("Quadrado", "Azul", 12);
    exibir_forma2d(*q);
    
    Forma2D *c = new Circulo("Circulo", "Vermelho", 9);
    exibir_forma2d(*c);

    Forma2D *t = new Triangulo("Triangulo", "Verde", 6, 3, 4);
    exibir_forma2d(*t);

    Forma3D *cb = new Cubo("Cubo", "Roxo", 3.4);
    exibir_forma3d(*cb);

    Forma3D *es = new Esfera("Esfera", "Laranja", 7);
    exibir_forma3d(*es);

    delete q;
    delete c;
    delete t;
    delete cb;
    delete es;

    return 0;
}