#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    double raio, altura;

    cin >> raio >> altura;
    cout << fixed << setprecision(2) << raio * raio * 3.1415 * altura << endl;
    
    return 0;
}