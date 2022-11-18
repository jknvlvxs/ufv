/*
README
Fontes de consulta:
https://stackoverflow.com/questions/26281979/c-loop-through-map
https://stackoverflow.com/questions/53610778/how-to-use-stdunique-to-remove-unique-character-in-vector-c
Pessoas com as quais discuti sobre este exercício:
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <set>

using namespace std;

void adicionaGrau(char c, vector<char> v, vector<pair<char, int>> &graus, map<char, vector<char>> &adj)
{
    for (char i : v)
        if (i == c)
            return;

    for (pair<char, int> &g : graus)
    {
        if (g.first == c)
        {
            int grau = g.second;

            for (char c : v)
            {
                for (pair<char, int> &g2 : graus)
                {
                    if (g2.first == c)
                    {
                        g2.second = grau + 1;

                        for (auto it = adj.begin(); it != adj.end(); it++)
                            if (it->first == g2.first)
                                v = it->second;

                        if (v.size() > 0)
                            adicionaGrau(c, v, graus, adj);
                    }
                }
            }
        }
    }
}

int main()
{

    vector<string> palavras;
    vector<char> letras;
    string st;

    while (getline(cin, st))
    {
        if (st == "#")
            break;
        palavras.push_back(st);
    }

    map<char, vector<char>> adj;

    for (int i = 0; i < palavras.size() - 1; i++)
    {
        string p1 = palavras[i];
        string p2 = palavras[i + 1];

        for (int j = 0; j < p1.length(); j++)
        {
            if (p1[j] != p2[j])
            {
                letras.push_back(p1[j]);
                letras.push_back(p2[j]);

                adj[p1[j]].push_back(p2[j]);
                break;
            }
        }
    }

    // Remover letras duplicadas
    set<char> seen;
    letras.erase(remove_if(letras.begin(), letras.end(), [&seen](char c)
                           { return !seen.insert(c).second; }),
                 letras.end());

    vector<pair<char, int>> graus;

    for (int i = 0; i < letras.size(); i++)
        graus.push_back(make_pair(letras[i], -1));

    // Seta os vetores que possuem grau = 0;
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        char c = it->first;
        int isDependencia = false;

        for (auto it2 = adj.begin(); it2 != adj.end(); it2++)
        {
            char c2 = it2->first;
            vector<char> v = it2->second;

            for (int i = 0; i < v.size(); i++)
                if (v[i] == c)
                {
                    isDependencia = true;
                    break;
                }
        }

        if (!isDependencia)
            for (int i = 0; i < graus.size(); i++)
            {
                if (graus[i].first == c)
                {
                    graus[i].second = 0;
                    break;
                }
            }
    }

    // Seta os graus dos outros vértices
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        char c = it->first;
        vector<char> v = it->second;

        for (int i = 0; i < graus.size(); i++)
            if (c == graus[i].first && graus[i].second == 0)
                adicionaGrau(c, v, graus, adj);
    }

    // print graus
    // for (auto it = graus.begin(); it != graus.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    int numPrint = 0;
    int order = 0;

    while (numPrint < letras.size())
    {
        for (auto it = graus.begin(); it != graus.end(); it++)
        {
            if (it->second == order)
            {
                cout << it->first;
                numPrint++;
            }
        }

        order++;
    }

    cout << endl;

    return 0;
}
