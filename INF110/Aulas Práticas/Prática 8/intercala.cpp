#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    int listaA[n], listaB[n];

    for(int i = 0; i < n; i++){
        cin >> listaA[i];
    }

    for(int i = 0; i < n; i++){
        cin >> listaB[i];
    }

    for(int i = 0; i < n; i++){
        cout << listaA[i] << " " << listaB[i] << " ";
    }
        
    cout << endl;
    
    return 0;
}