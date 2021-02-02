#include <iostream>
#include <math.h> 
using namespace std;

double primo (int num) {
    int divisores = 0;
     
    for (int i = 2; i < num/2; i++) {
        if (num % i == 0) {
            divisores++;
        }
    }
        
    return (divisores > 0 ? false : true);
}

int main () {
    for(int i = 2; i <= 1000; i++){
        if(primo(i)){
            cout << i << " ";
        }

        if(i % 100 == 0) cout << endl; // visual
    }

    return 0;
}