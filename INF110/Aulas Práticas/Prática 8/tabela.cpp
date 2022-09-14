#include <iostream>

using namespace std;

int main() {
    int d, f;
    cin >> d >> f;
    int dias[d][f], funcionarios[f][d];

    for(int i = 0; i < d; i++){
        for(int j = 0; j < f; j++){
            cin >> dias[i][j];
        }
    }

    for(int i = 0; i < f; i++){
        for(int j = 0; j < d; j++){
            cout << dias[j][i] << (j < d-1? " " : "");
        }
        cout << endl;
    }

    return 0;
}