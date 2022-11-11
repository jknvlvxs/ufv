/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int buscaVizinhos(vector<string> &mapa, int l, int c)
{
    int interno = 1;

    if (mapa[l][c] != '1')
        return 0;

    mapa[l][c] = '0';

    if (l < mapa.size() - 1)
    {
        interno += buscaVizinhos(mapa, l + 1, c);

        if (c < mapa[l].size() - 1)
            interno += buscaVizinhos(mapa, l + 1, c + 1);

        if (c > 0)
            interno += buscaVizinhos(mapa, l + 1, c - 1);
    }

    if (l > 0)
    {
        interno += buscaVizinhos(mapa, l - 1, c);

        if (c < mapa[l].size() - 1)
            interno += buscaVizinhos(mapa, l - 1, c + 1);

        if (c > 0)
            interno += buscaVizinhos(mapa, l - 1, c - 1);
    }

    if (c < mapa[l].size() - 1)
        interno += buscaVizinhos(mapa, l, c + 1);

    if (c > 0)
        interno += buscaVizinhos(mapa, l, c - 1);

    return interno;
}

int main()
{

    int t, space = 0;
    cin >> t;

    vector<string> mapa;
    vector<int> contadores(0);

    cin.ignore();
    cin.ignore();

    string st;

    while (getline(cin, st))
        mapa.push_back(st);

    for (int l = 0; l < mapa.size(); l++)
    {

        for (int c = 0; c < mapa[l].size(); c++)
            if (mapa[l][c] == '1')
                contadores.push_back(buscaVizinhos(mapa, l, c));

        if (mapa[l] == "" || l == mapa.size() - 1)
        {
            int max = 0;
            for (int i = 0; i < contadores.size(); i++)
                if (contadores[i] > max)
                    max = contadores[i];

            if (space++ > 0)
                cout << endl;

            cout << max << endl;

            contadores.clear();
        }
    }

    return 0;
}
