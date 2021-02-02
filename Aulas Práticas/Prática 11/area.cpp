#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

struct Ponto {
    int x,y;
};

double distancia (Ponto a, Ponto b){
    return sqrt(pow((a.x - b.x),2)+pow((a.y - b.y),2));
}

double area (Ponto p, Ponto q, Ponto r){
    double s = (distancia(p, q)+distancia(q, r)+distancia(r,p))/2;
    double area = s * (s-distancia(p, q)) * (s-distancia(q, r)) * (s-distancia(r, p));
    return sqrt(area);
}


int main() {
    Ponto pontos[3];
    
    for(int i = 0; i < 3; i++){
        cin >> pontos[i].x >> pontos[i].y;
    }

    cout << fixed << setprecision(2) << area(pontos[0], pontos[1], pontos[2]) << endl;
    return 0;
}