#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int i, j;
    int num, dig[5];

    cin >> num;

    for(i=0; num; i++){  
        dig[i] = num % 10;
        num /= 10;
    }

    for(j=0; j<i; j++) {
        num += dig[j] * pow(10, (i-j-1)); 
    }

    cout << num + 1;
        
    return 0;
}