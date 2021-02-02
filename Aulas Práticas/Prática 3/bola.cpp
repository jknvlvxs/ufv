#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int diametro, altura, largura, profundidade;

    cin >> diametro;
    cin >> altura >> largura >> profundidade;

    if (diametro <= altura && diametro <= largura && diametro <= profundidade ){
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    
    return 0;
}