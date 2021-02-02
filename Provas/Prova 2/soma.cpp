#include <iostream>

using namespace std;

int soma(int n) {
    int valor = 0;

    if(n > 0)
        valor = n % 10 + soma(n/10);

    return valor;
  
}

int main() {
    int num;
    cin >> num;
    cout << soma(num) << endl;

    return 0;
}