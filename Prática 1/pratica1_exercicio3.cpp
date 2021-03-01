// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

struct Jogador {
    int pontos ;
    int x , y ;
};

void leDadosJogador(Jogador *j){
    cout << "Informe os pontos do jogador: "; 
    cin >> j->pontos;
    cout << "Informe as coordenadas x e y do jogador: "; 
    cin >> j->x >> j->y;
}

int main () {
    Jogador jogadores[5];

    for(int i = 0; i < 5; i++){
        leDadosJogador(&jogadores[i]);
    }

    for(int i = 0; i < 5; i++){
        cout << "Jogador " << i+1 << ": ";
        cout << "Pontos: " << jogadores[i].pontos << " | ";
        cout << "Coordenadas: " << "x: " << jogadores[i].x << " y: " << jogadores[i].y << endl;
    }

    return 0;
}