#include <iostream>
using namespace std;

int main () {
    int n = 1;
    char caracter = '1';
    while(n != 0 && caracter != '.'){
        cin >> n >> caracter;
        for(int i = 0; i < n; i++){
            cout << caracter;
        }
    }

    cout << "." << endl;

    return 0;
}