#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    int repeticoes[t];
    bool possuirepeticoes[t];

    for(int i = 0; i < t; i++){
        possuirepeticoes[i] = false;
        int n;
        cin >> n;
        int elementos[n];
        for(int j = 0; j < n; j++){
            cin >> elementos[j];
        }

        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(j < k && elementos[j] == elementos[k]){
                    possuirepeticoes[i] = true;
                    repeticoes[i] = elementos[j];
                }
            }
        }
    }

    for(int i = 0; i < t; i++){
        if(possuirepeticoes[i]){
            cout << "SIM: " << repeticoes[i] << endl; 
        } else {
            cout << "NAO" << endl; 
        }
    }

    return 0;
}