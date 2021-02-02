#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    double valora, valorb, valorc;

    cin >> valora >> valorb >> valorc;

    double xpositivo = (valorb * -1 + sqrt(valorb * valorb - 4 * valora * valorc)) / (2 * valora);
    double xnegativo = (valorb * -1 - sqrt(valorb * valorb - 4 * valora * valorc)) / (2 * valora);

    cout << fixed << setprecision(4) << xpositivo << ' ' << xnegativo << endl;
    
    return 0;
}