#include <iostream>

using namespace std;

bool eh_primo(int num){
    int divisores = 0;

    for (int i = 2; i < num; i++) {
        if (num % i == 0 && num != 1) {
            divisores++;
        }
    }

    return (divisores > 0 || num == 1 ? false : true);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "Primos entre " << a << " e " << b << ":";
    for(int i = a; i <= b; i++)
        if (eh_primo(i)) //Se for primo
            cout << " " << i; //imprime o valor

    cout << endl;
    return 0;
}