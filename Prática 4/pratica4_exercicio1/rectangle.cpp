// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include "rectangle.h"

// Rectangle::Rectangle(double width, double length) {
Rectangle::Rectangle() {
    _width = 1;
    _length = 1;
    // _width = width;
    // _length = length;
}

double Rectangle::getWidth()  {
    return _width;
}

double Rectangle::getLength()  {
    return _length;
}

void Rectangle::setWidth(double width) {
    if(width > 0.0 && width < 20.0)
        _width = width;
}

void Rectangle::setLength(double length) {
    if(length > 0.0 && length < 20.0)
        _length = length;
}

double Rectangle::getPerimeter() {
    return 2 * (_width + _length);
}

double Rectangle::getArea() {
    return _width * _length;
}

Rectangle::~Rectangle() {

}