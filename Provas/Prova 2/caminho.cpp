#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int matrizM[n][n];
    bool caminho = true;
    int i = 0, j = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrizM[i][j];
        }
    }

    while((i < n-1 && j < n-1) && caminho == true){
        if(matrizM[i + 1][j] == 1)
            i++;
        else if(matrizM[i][j + 1] == 1)
            j++;
        else if(matrizM[i + 1][j + 1] == 1) {
            i++; j++;
        } else
            caminho = false;
    }

    cout << (caminho? "SIM" : "NAO") << endl;

    return 0;
}