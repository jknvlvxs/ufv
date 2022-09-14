// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>
#include "aquecedor.h"

using namespace std;

int main () {
    cout << setprecision(2) << fixed;

    // criação do objeto a1 utilizando o primeiro construtor
    Aquecedor *a1 = new Aquecedor();

    cout << "Temperatura Inicial: " << a1->getTemperatura() << "°C" << endl;

    a1->abaixarTemperatura();
    cout << "Temperatura Atual: " << a1->getTemperatura() << "°C" << endl;

    a1->setFatorIncremento(10.00);

    a1->aumentarTemperatura();
    cout << "Temperatura Atual: " << a1->getTemperatura() << "°C" << endl;
    
    a1->aumentarTemperatura();
    cout << "Temperatura Atual: " << a1->getTemperatura() << "°C" << endl;
    a1->aumentarTemperatura();
    cout << "Temperatura Atual: " << a1->getTemperatura() << "°C" << endl;

    delete a1;
    cout << endl;

    // criação do objeto a2 utilizando o segundo construtor
    Aquecedor *a2 = new Aquecedor(10.33);

    cout << "Temperatura Inicial: " << a2->getTemperatura() << "°C" << endl;

    a2->aumentarTemperatura();
    cout << "Temperatura Atual: " << a2->getTemperatura() << "°C" << endl;
    
    a2->abaixarTemperatura();
    cout << "Temperatura Atual: " << a2->getTemperatura() << "°C" << endl;
    a2->abaixarTemperatura();
    a1->setFatorIncremento(0.33);
    a2->abaixarTemperatura();
    cout << "Temperatura Atual: " << a2->getTemperatura() << "°C" << endl;

    delete a2;
    cout << endl;

    // criação do objeto a3 utilizando o terceiro construtor
    Aquecedor *a3 = new Aquecedor(18, 1);

    cout << "Temperatura Inicial: " << a3->getTemperatura() << "°C" << endl;

    a3->aumentarTemperatura();
    cout << "Temperatura Atual: " << a3->getTemperatura() << "°C" << endl;

    a1->setFatorIncremento(3);
    a3->abaixarTemperatura();
    cout << "Temperatura Atual: " << a3->getTemperatura() << "°C" << endl;
    a3->abaixarTemperatura();
    cout << "Temperatura Atual: " << a3->getTemperatura() << "°C" << endl;

    delete a3;
    
    return 0;
}