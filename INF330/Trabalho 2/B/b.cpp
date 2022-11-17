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
    // verticeDescoberto[v] = true;
    // acesso[v] = 0;

    int vertice;
    while (!fila.empty())
    {
        vertice = fila.front();
        fila.pop();

        for (int v : adj[vertice])
        {
            printf("vertice:%d -> v: %d\n", vertice, v);
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
    int nv;
    cin >> nv;

    vector<vector<int>> adj(nv);

    while (nv != 0)
    {
        cout << "nv: " << nv << endl;
        int i = 1;

        while (i != 0)
        {
            int j = 1;
            cin >> i;

            cout << "i: " << i << "\t";

            if (i != 0)
            {
                while (j != 0)
                {
                    cin >> j;
                    cout << "j: " << j << "\t";
                    if (j != 0)
                        adj[i - 1].push_back(j - 1);
                }
                cout << endl;
            }
        }

        int ni, v;

        cin >> ni;

        cout << "ni: " << ni << endl;

        vector<int> acesso(nv);
        vector<bool> verticeDescoberto(nv, false);

        for (int i = 0; i < nv; i++)
            acesso[i] = i + 1;

        for (int i = 0; i < ni; i++)
        {
            cin >> v;

            bfsFila(adj, verticeDescoberto, acesso, v - 1);

            cout << acesso.size() << " ";
            for (int p = 0; p < acesso.size(); p++)
            {
                cout << acesso[p] << " ";
            }
            cout << endl;
        }

        cin >> nv;
    }

    return 0;
}
