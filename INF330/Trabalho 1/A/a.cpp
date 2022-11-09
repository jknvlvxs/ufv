/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> m;
        int matriz[n][m];
        bool isIncidence = true;

        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> matriz[j][k];

        int u, v;
        int arestas[n][n] = {};

        for (int k = 0; k < m; k++)
        {
            int cont = 0;
            for (int j = 0; j < n; j++)
                if (matriz[j][k])
                    cont++ == 0 ? u = j : v = j;

            if (cont != 2 || arestas[u][v])
                isIncidence = false;

            arestas[u][v]++;
            arestas[v][u]++;

            if (!isIncidence)
                break;
        }

        cout << (isIncidence ? "Yes" : "No") << endl;
    }

    return 0;
}
