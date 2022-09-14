#include <iostream>
using namespace std;

int main () {
    int valorN;
    long long int fatorial = 1;

    cin >> valorN;

    for(int i = valorN; i >= 1; i--){
        fatorial = fatorial * i;
    }

    cout << fatorial << endl;
    
    return 0;
}