#include <iostream>

using namespace std;

bool bissexto(int ano){
    if(ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)){
        return true;
    }

    return false;
}

int main() {
    int ano = 1;

    while(ano > 0){
        cin >> ano;
        
        if(ano > 0)
            cout << (bissexto(ano)? "bissexto" : "nao bissexto") << endl;
    }
   
    return 0;
}