// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "posicoesvetor.h"
#include "invalidpositionexception.h"

using namespace std;

int main () {
    PosicoesVetor *vetor = new PosicoesVetor(7);
    
    try{
        while(1){
            int pos, val;
            cout << "Informe a posição do vetor: ";
            cin >> pos;
            cout << "Informe o valor: ";
            cin >> val;

            if(!cin) throw std::invalid_argument("Valor informado é inválido!");

            vetor->inserir_elemento(pos, val);
        }
    } catch (InvalidPositionException &er){
        cerr << er.what() << endl;
    } catch (std::invalid_argument &er){
        cerr << er.what() << endl;
    }

    delete vetor;

    return 0;
}