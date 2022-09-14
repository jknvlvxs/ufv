// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

class SavingsAccount {
    private:
        double savingsBalance;
    public:
        static double annualInterestRate;

        SavingsAccount(double savingsBalance);

        ~SavingsAccount();

        double calculateMonthlyInterest();
        static void modifyInterestRate(double annualInterestRate);
};