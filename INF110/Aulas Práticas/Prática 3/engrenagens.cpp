#include <iostream>

using namespace std;

int main () {
    int menorValor, maiorValor;

    cin >> menorValor >> maiorValor;
    cout << (maiorValor % menorValor == 0 ? 1 : 0) << endl;
    
    return 0;
}