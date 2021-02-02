#include <iostream>

using namespace std;

int main () {
    int valor;

    cin >> valor;

    if(valor % 2 == 0) {
        cout << valor << " e um numero par!" << endl;
    } else {
        cout << valor << " e um numero impar!" << endl;
    }
    
    return 0;
}