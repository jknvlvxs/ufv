#include <iostream>
#include <iomanip>

using namespace std;

double imposto(double v) {
    double aliquota = 0, parcela = 0;

    if(v >= 22847.77 && v <= 33919.80 ){
        aliquota = 7.5;
        parcela = 1713.58;
    } else if(v >= 33919.81 && v <= 45012.60 ){
        aliquota = 15;
        parcela = 4257.57;
    } else if(v >= 45012.61 && v <= 55976.16 ){
        aliquota = 22.5;
        parcela = 7633.51;
    } else if(v > 55976.16){
        aliquota = 27.5;
        parcela = 10432.32;
    }

    return (v * (aliquota / 100) - parcela);
}

int main() {
    double v = 1;

    while(v > 0){
        cin >> v;

        if (v > 0) 
            cout << "R$ " << fixed << setprecision(2) << imposto(v) << endl;
    }

    return 0;
}