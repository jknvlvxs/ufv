#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int matriza[n][n], matrizb[n][n], produto[n][n];
    bool irrevertivel = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriza[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrizb[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            produto[i][j] = 0;
            for (int k = 0; k < n; k++){
                produto[i][j] += matriza[i][k] * matrizb[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                if(produto[i][j] != 1){
                    irrevertivel = false;
                    break;
                }
            } else {
               if(produto[i][j] != 0){
                    irrevertivel = false;
                    break;
                } 
            }
        }
    }

    cout << (irrevertivel? "SIM" : "NAO") << endl;
    
    return 0;
}