#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    double valora, valorb, valorc;

    cin >> valora >> valorb >> valorc;

    double xpositivo = (valorb * -1 + sqrt(valorb * valorb - 4 * valora * valorc)) / (2 * valora);
    double xnegativo = (valorb * -1 - sqrt(valorb * valorb - 4 * valora * valorc)) / (2 * valora);

    if (!isnan(xpositivo) && !isnan(xnegativo) && xpositivo != xnegativo){
        cout << fixed << setprecision(2) << xnegativo << ' ' << xpositivo << endl;
    } else if (!isnan(xpositivo) && !isnan(xnegativo) && xpositivo == xnegativo){
        cout << fixed << setprecision(2) << xpositivo << endl;
    } else {
        cout << "Nao ha raiz real" << endl;
    }
    
    return 0;
}