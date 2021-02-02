#include <iostream>

using namespace std;

int main() {
    char str[100];
    cin.getline(str, 100);
    int pAberto = 0;
    bool verificador = true;

    for(int i = 0; str[i] != '\0'; i++){
        if((str[i] == '(')){
            pAberto++;
        }

        if((str[i] == ')')){
            if(pAberto > 0){
                pAberto--;
            } else {
                verificador = false;
                break;
            }
        } 
    }

    if(verificador == true){
        verificador = (pAberto == 0);
    }

    cout << (verificador ? "SIM" : "NAO") << endl;

    return 0;
}