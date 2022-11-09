/*
README
Fontes de consulta:
https://www.sciencedirect.com/science/article/pii/S0012365X09004683
https://djalil.chafai.net/blog/2014/11/13/the-erdos-gallai-theorem-on-the-degree-sequence-of-finite-graphs/
Pessoas com as quais discuti sobre este exercício:
*/
#include <iostream>
#include <algorithm>
#include <vector>

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

        for (int j = n - 1; j >= 0; j--)
            cin >> graus[j];

        for (int k = 1; k <= n; k++)
        {
            int somatorio_graus_1_a_k = 0;
            for (int i = 0; i < k; i++)
                somatorio_graus_1_a_k += graus[i];

            int somatorio_minimo = 0;
            for (int i = k; i < n; i++)
                somatorio_minimo += min(k, graus[i]);

            if (!(somatorio_graus_1_a_k <= k * (k - 1) + somatorio_minimo))
            {
                isSequence = false;
                break;
            }
        }

        cout << (isSequence ? "HAPPY" : "SAD") << endl;
    }

    return 0;
}
