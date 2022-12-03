/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

// Floyd-Warshall Maxmin
void floydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = max(dist[i][j], min(dist[i][k], dist[k][j]));
}

int main() {
    int nv; // Número de vértices
    int ne; // Número de arestas
    int cenario = 1;

    cin >> nv >> ne;

    while (nv != 0 && ne != 0) {
        vector<vector<int>> distancias(nv, vector<int>(nv, 0));

        for (int i = 0; i < ne; i++) {
            int u, v, peso;
            cin >> u >> v >> peso;
            distancias[u - 1][v - 1] = distancias[v - 1][u - 1] = peso;
        }

        int s;    // Starting City
        int d;    // Destination City
        double t; // Number of Tourists

        cin >> s >> d >> t;

        floydWarshall(distancias, nv);

        cout << "Scenario #" << cenario++ << endl;
        cout << "Minimum Number of Trips = " << ceil(t / (distancias[s - 1][d - 1] - 1)) << endl;
        cout << endl;

        cin >> nv >> ne;
    }

    return 0;
}