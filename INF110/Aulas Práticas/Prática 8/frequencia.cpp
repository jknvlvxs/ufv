#include <iostream>

using namespace std;

int main() {
    int m, n, v, contador;
    cin >> m >> n;

    int matriz[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    cin >> v;

    for(int i = 0; i < m; i++){
        contador = 0;
        for(int j = 0; j < n; j++){
            if(matriz[i][j] == v) contador++;
        }
        cout << contador << endl;
    }
    return 0;
}