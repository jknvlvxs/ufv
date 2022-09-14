// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>

#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main() {
    cout << setprecision(2) << fixed;

    Package pacote1("Entrega Normal", "177A Bleecker Street", 12, 2);
    TwoDayPackage pacote2("Entrega Normal", "177A Bleecker Street", 12, 2, 2.3);
    OvernightPackage pacote3("Entrega Normal", "177A Bleecker Street", 12, 2, 2.3);

    std::cout << "Entrega normal: R$" << pacote1.calculateCost() << std::endl;
    std::cout << "Entrega em dois dias: R$" << pacote2.calculateCost() << std::endl;
    std::cout << "Entrega noturna: R$" << pacote3.calculateCost() << std::endl;
    
    return 0;
}