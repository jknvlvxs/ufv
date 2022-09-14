// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include "excecaosoma.h"
#include "excecaoacimadex.h"

ExcecaoSoma::ExcecaoSoma() {

}

void ExcecaoSoma::setValor(int valor) {
    _valor = valor;
}

void ExcecaoSoma::inserir_numero(int numero) {
    if(_valor_somado + numero < _valor) {
        _valor_somado += numero;
        _quantidade_somados++;
    }
    else throw ExcecaoAcimaDeX();
}

int ExcecaoSoma::getValorSomado(){
    return _valor_somado;
}

int ExcecaoSoma::getQuantidadeSomados(){
    return _quantidade_somados;
}

double ExcecaoSoma::getMedia(){
    return (double) _valor_somado / (double) _quantidade_somados;
}