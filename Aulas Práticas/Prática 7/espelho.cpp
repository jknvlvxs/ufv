#include <iostream>

using namespace std;

int espelhar(int n) {
    int espelho = 0;

    for (; n; n/=10)
        espelho = espelho * 10 + n % 10;

    return espelho;
}

int main() {
    int a = 1, b = 1;

    while(a != 0 && b != 0){
        cin >> a >> b;

        if (a > 0 && b > 0) 
            cout << (espelhar(a) == b? "espelho" : "nao espelho") << endl;
    }

    return 0;
}