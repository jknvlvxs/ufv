#include <iostream>
using namespace std;

int main () {

    double altura[5], mediaIdades = 0, alturaF = 0, alturaM = 0;
    char sexo[5];
    int idade[5], quantF = 0, quantM = 0;

    for (int i = 0; i < 5; i++){
        cout << "Altura do "<< i+1 << "o Atleta: ";
        cin >> altura[i];
        cout << "Sexo do "<< i+1 << "o Atleta: ";
        cin >> sexo[i];
        cout << "Idade do "<< i+1 << "o Atleta: ";
        cin >> idade[i];
        cout << endl;
    }

    for (int i = 0; i < 5; i++){
        mediaIdades += idade[i];

        if(sexo[i] == 'F'){
            alturaF += altura[i];
            quantF++;
        }

        if(sexo[i] == 'M'){
            alturaM += altura[i];
            quantM++;
        }
    } 
    cout << "Media de Idades: " << mediaIdades / 5 << endl;

    cout << "Media de Altura Feminina: " << alturaF / quantF << endl;

    cout << "Media de Altura Masculina: " << alturaM / quantM << endl;

    return 0;
}