#include <iostream>
#include <cmath>
using namespace std;

int main () {

    int n;
    cin >> n;
    int matriz[n][n], somadp = 0, produtods = 1, qtdMedia = 0;
    double media = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
            media += matriz[i][j];
            if (i == j) somadp += matriz[i][j];
            if (i+j == n-1) produtods *= matriz[i][j];
        }   
    }

    media = media / (n*n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(matriz[i][j] < media) qtdMedia++;
        }
    }

    cout << "Media dos elementos: " << media << endl;
    cout << "Quantidade de elementos abaixo da media: " << qtdMedia << endl;
    cout << "Soma dos elementos da diagonal principal: " << somadp << endl;
    cout << "Produto dos elementos da diagonal secundaria: " << produtods << endl;

    return 0;
}