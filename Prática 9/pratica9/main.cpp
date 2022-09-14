// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

#include "soma.h"
#include "power.h"
#include "mdc.h"

int main () {
    // Exercício 1
    std::cout << "Exercício 1: Soma" << std::endl;
    Soma soma;
    int m, n;
    std::cout << "Digite m: ";
    std::cin >> m;
    std::cout << "Digite n: ";
    std::cin >> n;
    std::cout << soma.gerarSoma(m, n) << std::endl;

    // Exercício 2
    std::cout << std::endl << "Exercício 2: Potência" << std::endl;
    Power power;
    int k, n2;
    std::cout << "Digite k: ";
    std::cin >> k;
    std::cout << "Digite n: ";
    std::cin >> n2;
    std::cout << power.gerarPotencia(k, n2) << std::endl;

    // Exercício 3
    std::cout << std::endl << "Exercício 3: MDC" << std::endl;
    MDC mdc;
    int x, y;
    std::cout << "Digite x: ";
    std::cin >> x;
    std::cout << "Digite y: ";
    std::cin >> y;
    std::cout << mdc.gerarMdc(x, y) << std::endl;


    return 0;
}