#include <iostream>

using namespace std;

int main () {
    int num;
    long long int fibo = 0, primeiroTermo = 0, segundoTermo = 1;

    cin >> num;
    if (num == 1) fibo = 1;

    for(int i = 2; i <= num; i++){
        fibo = primeiroTermo + segundoTermo;
        primeiroTermo = segundoTermo;
        segundoTermo = fibo;
    }

    cout << fibo << endl;
        
    return 0;
}