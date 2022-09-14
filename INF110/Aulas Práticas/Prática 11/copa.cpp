#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct TipoPartida {
    char time1[31], time2[31];
    int placar1, placar2;
};

struct Pontuacao {
    char nome[31];
    int ponto;
};

int calcularPontuacao(Pontuacao time, TipoPartida partida[], int n){
    int pontuacao = 0;

    for(int i = 0; i < n; i++){
        if(strcmp (time.nome, partida[i].time1) == 0){
            if(partida[i].placar1 > partida[i].placar2) pontuacao += 3;
            if(partida[i].placar1 == partida[i].placar2) pontuacao += 1;
        }

        if(strcmp (time.nome, partida[i].time2) == 0){
            if(partida[i].placar2 > partida[i].placar1) pontuacao += 3;
            if(partida[i].placar2 == partida[i].placar1) pontuacao += 1;
        }
    }
    
    return pontuacao;
}

int main() {
    int n;
    cin >> n;
    char x;

    TipoPartida partida[50];
    Pontuacao grupo[4];

    for(int i = 0; i < n; i++){
        cin >> partida[i].time1;
        cin >> partida[i].placar1;
        cin >> x;
        cin >> partida[i].placar2;
        cin >> partida[i].time2;
        cin.ignore();
    }

    for(int i = 0; i < 4; i++){
        cin >> grupo[i].nome;
        grupo[i].ponto = calcularPontuacao(grupo[i], partida, n);
    }

    for(int i = 0; i < 4; i++){
        cout << grupo[i].nome << " " << grupo[i].ponto << endl;
    }

    return 0;
}