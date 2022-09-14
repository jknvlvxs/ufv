#include <iostream>

using namespace std;

int main () {
    int valorx, valory;

    cin >> valorx >> valory;
    
    if (valorx == 0 && valory == 0)
        cout << "ORIGEM" << endl;
    else if (valorx == 0)
        cout << "EIXO Y" << endl;
    else if (valory == 0)
        cout << "EIXO X" << endl;
    else {
        if(valorx > 0 && valory > 0){
            cout << "QUADRANTE 1" << endl;
        }
        if(valorx < 0 && valory > 0){
            cout << "QUADRANTE 2" << endl;
        }
        if(valorx < 0 && valory < 0){
            cout << "QUADRANTE 3" << endl;
        }
        if(valorx > 0 && valory < 0){
            cout << "QUADRANTE 4" << endl;
        }
    }
        
    return 0;
}