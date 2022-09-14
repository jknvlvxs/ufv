#include <iostream>

using namespace std;
void ordenar(int &a, int &b, int &c){
    int aux;
    while (a > b || b > c || a > c){
        if(b < a){
            aux = a;
            a = b;
            b = aux;
        }
        if(c < a){
            aux = a;
            a = c;
            c = aux;
        }  
        if(c < b){
            aux = b;
            b = c;
            c = aux;
        }
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    ordenar(a, b, c);

    cout << a << " " << b << " " << c << endl;

    return 0;
}