#include <iostream>

using namespace std;

int main () {
    int valora, valorb, valorc;

    cin >> valora >> valorb >> valorc;

    if (valora >= valorb && valora >= valorc){
        cout << valora << endl;
    } else if (valorb >= valora && valorb >= valorc){
        cout << valorb << endl;
    } else if (valorc >= valora && valorc >= valorb){
        cout << valorc << endl;
    }
    
    return 0;
}