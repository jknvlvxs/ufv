#include <iostream>

using namespace std;

int main () {
    int cedula, doce1, doce2, doce3;

    cin >> cedula >> doce1 >> doce2 >> doce3;

    if (cedula % doce1 == 0) {
        cout << cedula/doce1 << " doces de " << doce1 << " reais" << endl; 
    } else if (cedula % doce2 == 0) {
        cout << cedula/doce2 << " doces de " << doce2 << " reais" << endl;
    } else if (cedula % doce3 == 0) {
        cout << cedula/doce3 << " doces de " << doce3 << " reais" << endl;
    } else {
        cout << "Capivaristo ficara sem doce" << endl;
    }
        
    return 0;
}