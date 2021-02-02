#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int numeroA, numeroB;

    cin >> numeroA >> numeroB;

    if ((numeroA + numeroB) % 2 == 0){
        cout << (numeroA + numeroB) / 2 << endl;
    } else {
        cout << "Nao existe valor medio inteiro" << endl;
    }
        
    return 0;
}