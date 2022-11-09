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
        // FIXME
        int n;
        while (cin >> n)
        {
            bool isSequence = true;
            vector<int> graus(n + 1);
            for (int i = 1; i <= n; i++)
            {
                cin >> graus[i];
                isSequence &= (graus[i] < n);
            }

            sort(graus.begin() + 1, graus.end(), greater<int>());

            vector<int> soma_grau(n + 1);
            for (int k = 1; k <= n; k++)
            {
                soma_grau[k] = soma_grau[k - 1] + graus[k];
            }

            for (int k = 1; k <= n; k++)
                cout << graus[k] << " ";
            cout << endl;
            for (int k = 1; k <= n; k++)
                cout << soma_grau[k] << " ";
            cout << endl;

            int p = n;
            for (int k = 1; k <= n; k++)
            {
                cout << "k: " << k << " " << p << "\t";
                while (k > graus[p] && k < p)
                    p--;
                while (k > p)
                    p++;
                cout << "p: " << p << endl;
                int sum = k * (p - k) + soma_grau[n] - soma_grau[p];
                isSequence &= (soma_grau[k] <= k * (k - 1LL) + sum);
            }

            isSequence &= (soma_grau[n] % 2LL == 0);

            cout << (isSequence ? "HAPPY" : "SAD") << endl;
        }
    }

    return 0;
}
