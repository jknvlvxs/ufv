#include <iostream>
#include <math.h>  

using namespace std;

double sigmoide(double z){
    return (1 / (1 + exp(-z)));
}

int main () {
    double x[2][11] = {{2.7, 1.5, 5.5, 3.5, 3.1, 7.6, 1.5, 6.9, 8.6, 7.66}, {10.5, 11.8, 20.0, 15.2, 14.5, 14.5, 3.5, 8.5, 2.0, 3.5}};
    double y[11] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    double w[2] = {0.5, 0.5};
    double taxaAprendizado = 0.1; // valor α
    double z, sigZ;
    int epocas = 1000;

    for(int i = 0; i < epocas; i++){
        for(int j = 0; j < 10 ; j++){
            z = x[0][j] * w[0] + x[1][j] * w[1];
            sigZ = sigmoide(z);
            w[0] += taxaAprendizado * (y[j] - sigZ) * (sigZ * (1 - sigZ)) * x[0][j];
            w[1] += taxaAprendizado * (y[j] - sigZ) * (sigZ * (1 - sigZ)) * x[1][j];
            z = 0;
        }
    }

    cin >> x[0][10] >> x[1][10];
    y[10] = x[0][10] * w[0] + x[1][10] * w[1];
    y[10] = sigmoide(y[10]);
    cout << (y[10] > 0.5? 1 : 0) << endl;

    return 0;
}