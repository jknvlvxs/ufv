#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    long int **matriz = (long int **) malloc (n * sizeof(long int *));

    int dp = 0, ds = 0;

    for(int i = 0; i < n; i++){
        matriz[i] = (long int*) malloc (n * sizeof(long int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
            if(i == j)
                dp += matriz[i][j];
            if(i+j == n-1)
                ds += matriz[i][j];
        }
    }

    cout << dp - ds << endl;

    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}