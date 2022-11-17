/*
README
Fontes de consulta:
https://drive.google.com/file/d/1v-ZswssetY_nKqF8V5WBlv7mhiM952Bh/view?usp=sharing
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

// Codigo adaptado da implementacao do livro Competitive Programming
void tarjan(int u, const vector<vector<int>> &adj, vector<int> &dfsParent, vector<int> &dfsNum,
            vector<int> &dfsLow, vector<bool> &isArticulation, vector<pair<int, int>> &bridges,
            int &dfsCount, int &rootChildren, int dfsRoot)
{
    dfsLow[u] = dfsNum[u] = ++dfsCount; // dfsLow[u] <= dfsNum[u]
    for (int v : adj[u])
    {
        // vertices nao descobertos tem tempo de descoberto (dfsNum) 0
        if (dfsNum[v] == 0)
        {
            dfsParent[v] = u; // pai de v e' u (v foi descoberto por u)
            if (u == dfsRoot) // caso especial... precisamos contar quantas vezes descobrimos vertices a partir da raiz para descobrir se raiz e' articulacao...
                rootChildren++;

            tarjan(v, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges, dfsCount, rootChildren, dfsRoot);

            if (dfsLow[v] >= dfsNum[u])   // apos visitar v recursivamente, conseguimos chegar em um vertice em v ou antes passando por u? (sem voltar pela aresta v,u)
                isArticulation[u] = true; // store this information first
            if (dfsLow[v] > dfsNum[u])    // ponte?
                bridges.push_back(make_pair(u, v));
            dfsLow[u] = min(dfsLow[u], dfsLow[v]); // update dfsLow[u]
        }
        else if (v != dfsParent[u])                // cheguei de volta em um vertice ja descoberto... se nao passei pela aresta v,u de volta --> ciclo...
            dfsLow[u] = min(dfsLow[u], dfsNum[v]); // atualize dfsLow...
    }
}

void tarjan(const vector<vector<int>> &adj,
            vector<bool> &isArticulation, vector<pair<int, int>> &bridges)
{
    int nv = adj.size();
    isArticulation = vector<bool>(nv, false);
    bridges.resize(0);

    vector<int> dfsParent(nv, -1);
    vector<int> dfsLow(nv, 0);
    vector<int> dfsNum(nv, 0);
    int dfsCount = 0;

    for (int i = 0; i < nv; i++)
    {
        if (dfsNum[i] == 0)
        {
            int rootChildren = 0; // resete para cada CC!!
            tarjan(i, adj, dfsParent, dfsNum, dfsLow, isArticulation, bridges, dfsCount, rootChildren, i);
            isArticulation[i] = rootChildren > 1;
        }
    }
}

int main()
{

    int t, space = 0, n = 1;
    string st;

    while (n > 0)
    {
        cin >> n;
        cin.ignore();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++)
        {
            getline(cin, st);
            stringstream stream;
            stream << st;

            regex regex(R"(\d+)");
            smatch match;

            vector<int> v;
            while (regex_search(st, match, regex))
            {
                int x = stoi(match.str());
                v.push_back(x);
                st = match.suffix();
            }

            for (int j = 2; j < v.size(); j++)
            {
                adj[v[0]].push_back(v[j]);
                adj[v[j]].push_back(v[0]);
            }
        }

        vector<bool> isArticulation;
        vector<pair<int, int>> bridges;
        tarjan(adj, isArticulation, bridges);

        if (space++ > 0)
            cout << endl;

        printf("%d critical links\n", (int)bridges.size());
        sort(bridges.begin(), bridges.end());
        for (auto b : bridges)
            cout << b.first << " - " << b.second << endl;
        cin.ignore();
    }

    return 0;
}
