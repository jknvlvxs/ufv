#include <iostream>
using namespace std;

int main () {
    int portugueses[10], brasileiros[10];
    bool verificador;
    
    for(int i = 0; i < 10; i++){
        cin >> portugueses[i];
    }

    for(int i = 0; i < 10; i++){
        cin >> brasileiros[i];
    }

    for(int i = 0; i < 10; i++){
        verificador = false;
        for(int j = 0; j < 10; j++){
            if(portugueses[i] == brasileiros[j]){
                verificador = true;
            }
        }

        if(!verificador) cout << portugueses[i] << " ";
    }

    for(int i = 0; i < 10; i++){
        verificador = false;
        for(int j = 0; j < 10; j++){
            if(brasileiros[i] == portugueses[j]){
                verificador = true;
            }
        }

        if(!verificador) cout << brasileiros[i] << " ";
    }

    cout << endl;

    return 0;
}