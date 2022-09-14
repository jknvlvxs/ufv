#include <iostream>

using namespace std;

int main () {
    int numeroJogadas, linha, coluna, contador;
    char velha[3][3] = { {'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}}, jogador, vencedor = 'v';

    cin >> numeroJogadas;

    for(int i = 0; i < numeroJogadas; i++){
        cin >> jogador >> linha >> coluna;
        velha[linha][coluna] = jogador;
    }

    // verificador colunas
    for(int i = 0; i < 3; i++) {
        contador = 0;
        for(int j = 0; j < 2; j++) {
            if(velha[i][j] == 'x' || velha[i][j] == 'o'){
                if(velha[i][j] == velha[i][j+1])
                    contador++;
            }

            if(contador == 2) 
                vencedor = velha[i][j];
        }
    }

    // verificador linhas
    for(int i = 0; i < 3; i++) {
        contador = 0;
        for(int j = 0; j < 2; j++) {
            if(velha[j][i] == 'x' || velha[j][i] == 'o'){
                if(velha[j][i] == velha[j+1][i])
                    contador++;
            }

            if(contador == 2) 
                vencedor = velha[j][i];
        }
    }

    // verificador diagonal principal
    contador = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            if(velha[i][j] == 'x' || velha[i][j] == 'o'){
                if(i == j && velha[i][j] == velha[i+1][j+1])
                    contador++;
            }

            if(contador == 2) 
                vencedor = velha[0][0];
        }
    }

    // verificador diagonal secundária
    contador = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(velha[i][j] == 'x' || velha[i][j] == 'o'){
                if(i + j == 2 && velha[i][j] == velha[i+1][j-1])
                    contador++;
            }

            if(contador == 2) 
                vencedor = velha[0][2];
        }
    }

    if(vencedor == 'v'){
        cout << "Velha!" << endl;
    } else {
        cout << "Venceu " << vencedor << "!" << endl;
    }

    return 0;
}