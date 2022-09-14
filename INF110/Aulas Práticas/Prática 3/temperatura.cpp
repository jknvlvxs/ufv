#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    double temperatura;
    char escala;

    cin >> temperatura >> escala;

    if ('C' == escala){
        cout << fixed << setprecision(1) << temperatura * 1.8 + 32 << " F" << endl;
    } else if ('F' == escala){
        cout << fixed << setprecision(1) << (temperatura - 32) / 1.8 << " C" << endl;
    }
    
    return 0;
}