#include <iostream>

using namespace std;

int main () {
    int novoJogador, numeroJogadores, idadeRegra, limiteJogadores, contadorJogadores = 0;

    cin >> numeroJogadores >> idadeRegra >> limiteJogadores ;

    for(int i = 1; i <= numeroJogadores; i++){
        cin >> novoJogador;
        if(novoJogador >= idadeRegra){
            contadorJogadores++;
        }
    }

    if (contadorJogadores > limiteJogadores)
        cout << "Nao aceito." << endl;
    else
        cout << "Aceito." << endl;
        
    return 0;
}