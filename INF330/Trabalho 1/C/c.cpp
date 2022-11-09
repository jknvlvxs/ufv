/*
README
Fontes de consulta:
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        bool isSequence = true;

        vector<int> graus(n, 0);

        for (int j = 0; j < n; j++)
            cin >> graus[j];

        vector<int> soma_grau(n, 0);
        for (int j = n - 1; j >= 0; j--)
        {
            int pos = n - 1 - j;
            soma_grau[pos] = graus[j] + soma_grau[pos - 1];
        }

        // for (int k = 0; k < n; k++)
        //     cout << graus[k] << " ";
        // cout << endl;
        // for (int k = 0; k < n; k++)
        //     cout << soma_grau[k] << " ";
        // cout << endl;

        int p = n;
        for (int k = 1; k <= n; k++)
        {
            while (k < p && k > graus[n - p])
                p--;
            while (k > p)
                p++;
            int soma = k * (p - k) + soma_grau[n - 1] - soma_grau[p - 1];
            if (!(soma_grau[k - 1] <= k * (k - 1) + soma))
                isSequence = false;
        }

        cout << (isSequence ? "HAPPY" : "SAD") << endl;
    }

    return 0;
}
