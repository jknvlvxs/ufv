#include <iostream>
#include <climits>

using namespace std;

int maior(int v[], int posicao, int n) {
    int valor = INT_MIN;

    if(posicao < n){
        int num = maior(v, posicao+1, n);

        if(v[posicao] > num)
            valor = v[posicao];
        else 
            valor = num;
    }

    return valor;
}

int main() {
    int n;
    cin >> n;
    int vetor[n];

    for(int i = 0; i < n; i++){
        cin >> vetor[i];
    }

    cout << maior(vetor, 0, n) << endl;

    return 0;
}