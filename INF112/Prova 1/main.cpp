// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>

#include "conta.h"
#include "contacorrente.h"
#include "contapoupanca.h"

using namespace std;

int main() {
    cout << setprecision(2) << fixed;

    cout << "-Conta-" << endl;
    Conta conta1("José Júlio Alves Campolina", "02083926617", 1000);
    cout << "Saldo atual: R$" << conta1.get_saldo() << endl;
    conta1.set_saldo(1200);
    cout << "Saldo atual: R$" << conta1.get_saldo() << endl << endl;

    cout << "-Conta Corrente-" << endl;
    ContaCorrente conta2("José Júlio Alves Campolina", "02083926617", 600);
    cout << "Saldo atual: R$" << conta2.get_saldo() << endl;
    conta2.set_saldo(700);
    cout << "Saldo atual: R$" << conta2.get_saldo() << endl << endl;

    cout << "-Conta Poupança-" << endl;
    ContaPoupanca conta3("José Júlio Alves Campolina", "02083926617", 9000, 120);
    cout << "Saldo atual: R$" << conta3.get_saldo() << endl;
    conta3.muda_rendimento(300);
    cout << "Saldo atual: R$" << conta3.get_saldo() << endl;

    return 0;
}