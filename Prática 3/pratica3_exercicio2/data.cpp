// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>
#include <ctime>
#include "data.h"

Data::Data(int dia, int mes, int ano) {
    _dia = dia;
    _mes = mes;
    _ano = ano;
}

void Data::getDataBarra() {
    std::cout << std::setfill('0') << std::setw(2) << _dia << "/" << std::setfill('0') << std::setw(2) << _mes << "/" << _ano << std::endl;
}

void Data::getDataExtenso() {
    const char *meses[12] = { "janeiro", "fevereiro", "marco", "abril", "maio", "junho", "julho", "agosto", "setembro", "outubro", "novembro", "dezembro" };
    std::cout << _dia << " de " << meses[_mes-1] << " de "<< _ano << std::endl;
}

void Data::getDataEmSegundos() {
    struct tm y2k = {0};
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = _ano-1900; y2k.tm_mon = _mes-1; y2k.tm_mday = _dia;

    std::time_t result = std::mktime(&y2k);
    // std::cout << std::asctime(std::localtime(&result));
    std::cout << result << " segundos" << std::endl;
}

Data::~Data() {}