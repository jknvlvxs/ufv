#include <omp.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int tamanho = 1000;

    vector<vector<int>> m1(tamanho, vector<int>(tamanho, 0));
    vector<vector<int>> m2(tamanho, vector<int>(tamanho, 0));
    vector<vector<int>> m3(tamanho, vector<int>(tamanho, 0));

    clock_t tInicio, tFim, tDecorrido;

    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            m1[i][j] = rand() % 5 + 1;
            m2[i][j] = rand() % 5 + 1;
        }

    int i, j, x, aux;

    /* SEQUENCIAL */
    tInicio = omp_get_wtime();

    for (i = 0; i < tamanho; i++)
        for (j = 0; j < tamanho; j++)
        {
            int aux = 0;

            for (x = 0; x < tamanho; x++)
                aux += m1[i][x] * m2[x][j];

            m3[i][j] = aux;
            aux = 0;
        }

    tFim = omp_get_wtime();

    tDecorrido = (tFim - tInicio);

    cout << "SEQUENCIAL:" << tDecorrido << endl;

    /* EXTERNO */
    tInicio = omp_get_wtime();

#pragma omp parallel for default(none) private(i, j, aux, x) shared(tamanho, m1, m2, m3)
    for (i = 0; i < tamanho; i++)
        for (j = 0; j < tamanho; j++)
        {
            aux = 0;

            for (x = 0; x < tamanho; x++)
                aux += m1[i][x] * m2[x][j];

            m3[i][j] = aux;
            aux = 0;
        }

    tFim = omp_get_wtime();

    tDecorrido = (tFim - tInicio);

    cout << "EXTERNO:" << tDecorrido << endl;

    /* INTERMEDIARIO */
    tInicio = omp_get_wtime();

    for (i = 0; i < tamanho; i++)
#pragma omp parallel for default(none) private(j, aux, x) shared(tamanho, m1, m2, m3, i)
        for (j = 0; j < tamanho; j++)
        {
            aux = 0;

            for (x = 0; x < tamanho; x++)
                aux += m1[i][x] * m2[x][j];

            m3[i][j] = aux;
            aux = 0;
        }

    tFim = omp_get_wtime();

    tDecorrido = (tFim - tInicio);

    cout << "INTERMEDIÁRIO:" << tDecorrido << endl;

    /* INTERNO */
    tInicio = omp_get_wtime();

    {
        for (i = 0; i < tamanho; i++)

            for (j = 0; j < tamanho; j++)
            {
                aux = 0;

#pragma omp parallel for reduction(+ \
                                   : aux)
                for (x = 0; x < tamanho; x++)
                    aux += m1[i][x] * m2[x][j];

                m3[i][j] = aux;
                aux = 0;
            }
    }

    tFim = omp_get_wtime();

    tDecorrido = (tFim - tInicio);

    cout << "INTERNO:" << tDecorrido << endl;

    return 0;
}