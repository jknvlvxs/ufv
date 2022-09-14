#include <iostream>
#include "Mediana.h"
#include <algorithm>
using namespace std;

void Mediana::insere(int el) {
    maiores.push(el);
    menores.push(maiores.top() * -1);
    maiores.pop(); 
    
    if (menores.size() > maiores.size() + 1) {
        maiores.push(menores.top() * -1);
        menores.pop();
    }
}

int Mediana::getMediana() {
    if (menores.size() == 0) return maiores.top();
    else if(maiores.size() == menores.size()) return (maiores.top() + menores.top() * -1) /2;  
    else return menores.top() * -1;
}


