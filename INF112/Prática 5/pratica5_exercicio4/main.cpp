#include "vaca.h"
#include "cachorro.h"
#include <iostream>
#include <vector>

int main(void) {
    std::vector <Animal*> fazenda;
    fazenda.push_back(new Vaca("marrom",10));
    fazenda.push_back(new Cachorro("branco"));
    fazenda[0]->faz_barulho();
    popula(fazenda,fazenda[0],10);
    for(unsigned int i=0;i<fazenda.size();i++){
        std::cout<<fazenda[i]->get_id()<<std::endl;
        delete fazenda[i];
    }
    
    /*Deve imprimir
    Muuu
    1
    2
    3
    4
    5
    6
    7
    8
    9
    10
    */

}