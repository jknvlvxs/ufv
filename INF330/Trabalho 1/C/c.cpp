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

        sort(graus.begin(), graus.end(), greater<int>());

        cout << endl;
        for (int k = 0; k < n; k++)
            cout << graus[k] << " ";
        cout << endl;

        for (int k = 1; k <= n; k++)
        {
            int somatorio_graus_1_a_k = 0;
            for (int i = 0; i < k; i++)
                somatorio_graus_1_a_k += graus[i];

            int somatorio_minimo = 0;
            for (int i = k; i < n; i++)
                somatorio_minimo += min(k, graus[i]);

            bool teste = somatorio_graus_1_a_k <= k * (k - 1) + somatorio_minimo;
            cout << "bool teste = " << somatorio_graus_1_a_k << " <= " << k << " * " << (k - 1) << " + " << somatorio_minimo << "\t" << teste << endl;
        }

        cout << (isSequence ? "HAPPY" : "SAD") << endl;
    }

    return 0;
}
