#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int eq2grau(double a, double b, double c, double &x1, double &x2){
    x1 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    x2 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);

    if(isnan (x1) && isnan (x2)) return 0;
    else if (x1 == x2) return 1;
    else return 2;
}

int main() {
    double a, b, c, x1 = 0, x2 = 0;
    int nRaizes;
    cin >> a >> b >> c;
    nRaizes = eq2grau(a, b, c, x1, x2);

    if(nRaizes == 0) cout << "Nao ha raiz real" << endl;
    else if (nRaizes == 1) cout << fixed << setprecision(2) << x1 << endl;
    else cout << fixed << setprecision(2) << x1 << " " << x2 << endl;

    return 0;
}