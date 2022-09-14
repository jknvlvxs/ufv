#include <iostream>

using namespace std;

int main () {
    int n, produto = 0;
    cin >> n;
    int listaA[n], listaB[n];

    for(int i = 0; i < n; i++){
        cin >> listaA[i];
    }

    for(int i = 0; i < n; i++){
        cin >> listaB[i];
    }

    for(int i = 0; i < n; i++){
        produto += listaA[i] * listaB[i];
    }

    cout << produto << endl;
        
    return 0;
}