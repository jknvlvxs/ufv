#include <iostream>

using namespace std;

int main () {
    int num, divisores = 0;

    cin >> num;
     
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisores++;
        }
    }
    
    if (divisores > 1)
        cout << "Nao primo." << endl;
    else
        cout << "Primo." << endl;
        
    return 0;
}