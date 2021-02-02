#include <iostream>

using namespace std;

int main() {
    int m, n, b, contador;
    cin >> m >> n >> b;
    int tabuleiro[m][n];

    for(int i = 0; i < b; i++){
        int xi, yi;
        cin >> xi >> yi;
        tabuleiro[xi-1][yi-1] = 9;
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            contador = 0;
            if(tabuleiro[i][j] != 9){
                if(i > 0 && tabuleiro[i-1][j] == 9) contador++;
                if(i < m-1 && tabuleiro[i+1][j] == 9) contador++;
                if(j > 0 && tabuleiro[i][j-1] == 9) contador++;
                if(j < n-1 && tabuleiro[i][j+1] == 9) contador++;
                if(i > 0 && j > 0 && tabuleiro[i-1][j-1] == 9) contador++;
                if(i < m-1 && j < n-1 && tabuleiro[i+1][j+1] == 9) contador++;
                if(i > 0 && j < n-1 && tabuleiro[i-1][j+1] == 9) contador++;
                if(i < m-1 && j > 0 && tabuleiro[i+1][j-1] == 9) contador++;

                if(contador == 0){
                    cout << "-";
                } else {
                    cout << contador;
                }
            } else {
                cout << "B";
            }
        }
        cout << endl;
    }

    return 0;
}