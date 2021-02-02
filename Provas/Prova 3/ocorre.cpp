#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char a[100], b[100];
    int contador = 0;
    int contadorInterno = 0;

    cin >> b >> a;

    // for(int i=0;i<strlen(a);i++){
    //     contadorInterno = 0;
    //     for(int j=0;j<strlen(b);){
    //         if(a[i]==b[j]){
    //             i++;
    //             j++;
    //             contadorInterno++;
    //         } else {
    //             j = strlen(b);
    //         }
    //     }
    //     cout << contadorInterno << endl;
    // }

    // cout << contador << endl;
    while (true) {
        pos = a.indexOf (b, pos + 1); 
        if (pos < 0) break;
        contador ++;
    }
    
    cout << contador << endl;  

    return 0;
}