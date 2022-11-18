/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

void bfsFila(const vector<vector<int>> &adj, vector<bool> &verticeDescoberto, vector<int> &ordem, const int v)
{
    queue<int> fila;
    fila.push(v);
    verticeDescoberto[v] = true;
    ordem[v] = 0;

    int vertice;
    while (!fila.empty())
    {
        vertice = fila.front();
        fila.pop();

        for (int v : adj[vertice])
        {
            if (!verticeDescoberto[v])
            {
                verticeDescoberto[v] = true;
                ordem[v] = ordem[vertice] + 1;
                fila.push(v);
            }
        }
    }
}

int main()
{

    int n;

    cin >> n;

    while (n != 0)
    {

        vector<pair<int, int>> arestas(n);

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            arestas[i] = make_pair(a, b);
        }

        sort(arestas.begin(), arestas.end());

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            vector<pair<double, int>> distancia;

            for (int j = 0; j < n; ++j)
                if (i != j)
                    distancia.push_back(make_pair(sqrt(pow(arestas[i].first - arestas[j].first, 2) + pow(arestas[i].second - arestas[j].second, 2)), j));

            sort(distancia.begin(), distancia.end());
            adj[i].push_back(distancia[0].second);
            adj[i].push_back(distancia[1].second);
        }

        int inicio = 0;
        for (int i = 0; i < n; ++i)
            if (arestas[i] == arestas[0])
            {
                inicio = i;
                break;
            }

        vector<bool> verticeDescoberto(n, false);
        vector<int> ordem(n, 0);

        bfsFila(adj, verticeDescoberto, ordem, inicio);

        bool chegou_em_todos = true;

        for (int i = 0; i < n; ++i)
            if (!verticeDescoberto[i])
            {
                chegou_em_todos = false;
                break;
            }

        if (chegou_em_todos)
            cout << "All stations are reachable." << endl;
        else
            cout << "There are stations that are unreachable." << endl;

        cin >> n;
    }

    return 0;
}
