#include <iostream>
#include <cmath>
using namespace std;

int main () {

    int m, n;
    cin >> m >> n;
    int matriz1[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz1[i][j];
        }   
    }

    int p, q;
    cin >> p >> q;
    int matriz2[p][q];

    for(int i = 0; i < p; i++){
        for(int j = 0; j < q; j++){
            cin >> matriz2[i][j];
        }   
    }

    int maiorL = p > m ? p : m, maiorC = q > n ? q : n;

    int matriz3[maiorL][maiorC];
    for(int i = 0; i < maiorL; i++){
        for(int j = 0; j < maiorC; j++){
            matriz3[i][j] = matriz1[i][j] * matriz2[j][i];
            cout << matriz3 << " ";
        }   
        cout << endl;
    }


    return 0;
}