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
        bool isIncidence = true;

        cin >> n;
        cin >> m;

        vector<vector<int>> matriz(n, vector<int>(m, 0));

        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                cin >> matriz[j][k];

        vector<vector<int>> arestas(n, vector<int>(n, 0));

        for (int k = 0; k < m; k++)
        {
            int cont = 0;
            int u = 0, v = 0;

            for (int j = 0; j < n; j++)
                if (matriz[j][k])
                    cont++ == 0 ? u = j : v = j;

            if (cont != 2 || arestas[u][v])
            {
                isIncidence = false;
                break;
            }

            arestas[u][v]++;
            arestas[v][u]++;
        }

        cout << (isIncidence ? "Yes" : "No") << endl;
    }

    return 0;
}
