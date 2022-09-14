// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "savings.h"

using namespace std;

int main(void) {
    // Main. Criando duas contas .
    SavingsAccount saver1 = SavingsAccount(2000);
    SavingsAccount saver2 = SavingsAccount(3000);

    // Alterando atributo static publico
    SavingsAccount::annualInterestRate = 3.00;

    // Imprimindo o monthly balance
    cout << saver1.calculateMonthlyInterest() << endl;
    cout << saver2.calculateMonthlyInterest() << endl;

    // Alterando atributo static publico
    SavingsAccount::modifyInterestRate(4.00);

    // Imprimindo o monthly balance. Tem que mudar para as duas classes.
    cout << saver1.calculateMonthlyInterest() << endl;
    cout << saver2.calculateMonthlyInterest() << endl;

    return 0;
}