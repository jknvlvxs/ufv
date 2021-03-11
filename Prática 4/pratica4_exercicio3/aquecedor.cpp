// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "aquecedor.h"

using namespace std;

Aquecedor::Aquecedor() {
    _temperatura = 20.00;
    _temperatura_minima = 10.00;
    _temperatura_maxima = 40.00;
    _fator_incremento = 5.00;
}

Aquecedor::Aquecedor(double temperatura) {
    _temperatura = temperatura;
    _temperatura_minima = 10.00;
    _temperatura_maxima = 40.00;
    _fator_incremento = 5.00;
}

Aquecedor::Aquecedor(double temperatura, double fator_incremento) {
    _temperatura = temperatura;
    _temperatura_minima = 10.00;
    _temperatura_maxima = 40.00;
    _fator_incremento = fator_incremento;
}

double Aquecedor::getTemperatura()  {
    return _temperatura;
}

void Aquecedor::aumentarTemperatura(){
    if(_temperatura + _fator_incremento <= _temperatura_maxima){
        _temperatura += _fator_incremento;
        cout << "Aumentou a temperatura em " << _fator_incremento << "°C" << endl;
    } else
        cout << "Não foi possível aumentar a temperatura pois excederia a temperatura máxima de " << _temperatura_maxima << "°C" << endl;
}

void Aquecedor::abaixarTemperatura(){
    if(_temperatura - _fator_incremento >= _temperatura_minima) {
        _temperatura -= _fator_incremento;
        cout << "Abaixou a temperatura em " << _fator_incremento << "°C" << endl;
    }
    else
        cout << "Não foi possível reduzir a temperatura pois excederia a temperatura mínima de " << _temperatura_minima << "°C" << endl;
}

void Aquecedor::setFatorIncremento(double fator_incremento) {
    _fator_incremento = fator_incremento;
}

Aquecedor::~Aquecedor() {

}