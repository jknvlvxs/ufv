// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "savings.h"

using namespace std;

double SavingsAccount::annualInterestRate = 0;

SavingsAccount::SavingsAccount(double value) {
    savingsBalance = value;
}

double SavingsAccount::calculateMonthlyInterest(){
    double monthlyBalance = savingsBalance * ((annualInterestRate/100) / 12);
    savingsBalance += monthlyBalance;
    return monthlyBalance;
}

void SavingsAccount::modifyInterestRate(double value){
    annualInterestRate = value;
}

SavingsAccount::~SavingsAccount() {

}