#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    double valora, valorb;

    cin >> valora >> valorb;
    cout << fixed << setprecision(2) << valora / valorb << endl;
    
    return 0;
}