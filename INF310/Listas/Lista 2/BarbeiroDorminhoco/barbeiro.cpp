#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

#define NUM_CLIENTES 100;
#define NUM_CADEIRAS 5;

class MonitorBarbearia
{
private:
    mutex mux;

    condition_variable proximo, cliFila, cliPronto;

    int numClientes, numCadeiras;
    vector<int> fila;
    long contadorClientes = 0;

public:
    MonitorBarbearia()
    {
        numCadeiras = NUM_CADEIRAS;
        numClientes = NUM_CLIENTES;
    }

    bool barbeiro_faz_corte()
    {
        unique_lock<mutex> lck(mux);

        if (contadorClientes++ == numClientes)
            return false;

        cliFila.wait(lck, [this]
                     { return fila.size() > 0; });

        proximo.notify_one();
        fila.erase(fila.begin());

        printf("Barbeiro chama o próximo cliente\n");

        cliPronto.wait(lck);

        return true;
    };

    void cliente_chega(int id)
    {
        unique_lock<mutex> lck(mux);

        if (fila.size() >= numCadeiras)
        {
            printf("Cliente %d foi embora\n", id);
            contadorClientes++;
            return;
        }

        printf("Cliente %d entrou na fila\n", id);
        fila.push_back(id);
        cliFila.notify_one();
        proximo.wait(lck);

        printf("Cliente %d foi atendido\n", id);
        cliPronto.notify_one();
    }
};

MonitorBarbearia barbearia;

void barbeiro()
{
    while (barbearia.barbeiro_faz_corte())
        ;
}

void cliente(int id)
{
    barbearia.cliente_chega(id);
}

int main()
{
    int numClientes = NUM_CLIENTES;
    vector<thread> threads;

    threads.push_back(thread(barbeiro));

    for (int i = 0; i < numClientes; i++)
        threads.push_back(thread(cliente, i));

    for (thread &t : threads)
        t.join();

    return 0;
};