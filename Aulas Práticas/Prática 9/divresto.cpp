#include <iostream>

using namespace std;

bool divresto(int dividendo, int divisor, int &resultado, int &resto){
    if(divisor > 0){
        resultado = dividendo / divisor;
        resto = dividendo % divisor;
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, dividendo,  divisor, resultado = 0, resto = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> dividendo >> divisor;
        if(divresto(dividendo, divisor, resultado, resto)){
            cout << resultado << " " << resto << endl;
        } else {
            cout << "indefinido" << endl;
        }
    }
    
    return 0;
}