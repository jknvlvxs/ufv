// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>

#include "excecaosoma.h"
#include "excecaoacimadex.h"

using namespace std;

int inputx() {
    int x = -1;
    while(x <= 0 || x > 100){
        try{
            cout << "Informe o valor x: ";
            cin >> x;

            if(!cin || x < 0 || x > 100)
                throw std::invalid_argument("Valor inválido! O valor deve ser entre 1 e 100!");

            return x;
        } catch (exception &e){
            cout << e.what() << endl;
        }
    }
    
    return 0;
}

int inputn() {
    int x = -1;
    while(x < 0){
        try{
            cout << "Informe o valor n: ";
            cin >> x;

            if(!cin || x <= 0)
                throw std::invalid_argument("Valor inválido! O valor deve ser maior que 0!");

            return x;
        } catch (exception &e){
            cout << e.what() << endl;
        }
    }
    
    return 0;
}

int main () {
    ExcecaoSoma *ex = new ExcecaoSoma();
    ex->setValor(inputx());
    
    try{
        while(1){
            ex->inserir_numero(inputn());
        }
    } catch (ExcecaoAcimaDeX &err){
        cerr << err.what() << endl;
    }

    cout << "Valor somado: " << ex->getValorSomado() << endl;
    cout << "Quantidade de números somados: " <<  ex->getQuantidadeSomados() << endl;
    cout << "Média: " << setprecision(3) << ex->getMedia() << endl;

    delete ex;

    return 0;
}