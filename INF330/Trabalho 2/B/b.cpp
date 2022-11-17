/*
README
Fontes de consulta:
https://stackoverflow.com/questions/11581940/removing-zeros-from-an-array-and-resizing-the-array-to-the-new-amount-of-element
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void bfsFila(const vector<vector<int>> &adj, vector<bool> &verticeDescoberto, vector<int> &acesso, const int v)
{
    queue<int> fila;
    fila.push(v);

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
                acesso[v] = 0;
                fila.push(v);
            }
        }
    }

    acesso.erase(remove(acesso.begin(), acesso.end(), 0), acesso.end());
}

int main()
{
    int nv, i, j;
    cin >> nv;

    while (nv != 0)
    {
        vector<vector<int>> adj(nv);

        cin >> i;

        while (i != 0)
        {
            cin >> j;

            while (j != 0)
            {
                if (j != 0)
                    adj[i - 1].push_back(j - 1);

                cin >> j;
            }

            cin >> i;
        }

        int ni, v;

        cin >> ni;

        for (int i = 0; i < ni; i++)
        {
            cin >> v;

            vector<int> acesso(nv);
            vector<bool> verticeDescoberto(nv, false);

            for (int i = 0; i < nv; i++)
                acesso[i] = i + 1;

            bfsFila(adj, verticeDescoberto, acesso, v - 1);

            cout << acesso.size();
            for (int p = 0; p < acesso.size(); p++)
                cout << " " << acesso[p];
            cout << endl;
        }

        cin >> nv;
    }

    return 0;
}
