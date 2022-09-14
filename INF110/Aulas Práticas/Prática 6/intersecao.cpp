#include <iostream>

using namespace std;

int main () {
    int m, n;
    cin >> m >> n;
    int listaA[m], listaB[n];

    for(int i = 0; i < m; i++){
        cin >> listaA[i];
    }

    for(int i = 0; i < n; i++){
        cin >> listaB[i];
    }

    cout << "{";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(listaA[i] == listaB[j])
            cout << listaA[i] << " ";
        }
    }

    cout << "}" << endl;

    return 0;
}