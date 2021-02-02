#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int votoC = 0, votoD = 0, votoE = 0, votoR = 0, votoT = 0, validador = 0;
    char voto;

    while(voto != 'X'){
        cin >> voto;
        if(voto == 'C') votoC++;
        if(voto == 'D') votoD++;
        if(voto == 'E') votoE++;
        if(voto == 'R') votoR++;
        if(voto == 'T') votoT++;
    }

    int resultado[5] = {votoC, votoD, votoE, votoR, votoT};
    int votosTotais = votoC + votoD + votoE + votoR + votoT;
    
    for(int i = 0; i < 5; i++){
        if(resultado[i] > (votosTotais / 2)){
            validador = 1;
        }
    }

    if (validador == 0) cout << "NAO" << endl;
    else cout << "SIM" << endl;

    return 0;
}