#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

#define NUM_VOLTAS 1000
#define CAPACIDADE_CARRO 10
#define TOTAL_VISITANTES 100

class MonitorMontanhaRussa
{
private:
    int totalVoltas;
    vector<int> carro;
    mutex mux;
    condition_variable carro_livre, carro_cheio;
    condition_variable encheu, esvaziou;
    condition_variable trans_in, trans_out;

public:
    MonitorMontanhaRussa(int numPassageiros)
    {
    }

    // ~MonitorMontanhaRussa()
    // {
    // }

    void espera_encher()
    {
        unique_lock<mutex> lck(mux);

        carro_livre.notify_all();

        encheu.wait(lck, [this]
                    { return carro.size() == CAPACIDADE_CARRO; });

        printf("Carro cheio\n");
    };

    void espera_esvaziar()
    {
        unique_lock<mutex> lck(mux);

        carro_cheio.notify_all();

        esvaziou.wait(lck, [this]
                      { return carro.size() == 0; });

        printf("Carro vazio\n");
    };

    void entra_no_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        carro_livre.wait(lck, [this]
                         { return carro.size() < CAPACIDADE_CARRO; });

        printf("Visitante %d entrou no carro\n", id);
        carro.push_back(id);

        if (carro.size() == CAPACIDADE_CARRO)
            encheu.notify_all();
    };

    void sai_do_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        carro_cheio.wait(lck, [this]
                         { return carro.size() > 0; });

        for (int i = 0; i < carro.size(); i++)
        {
            if (carro[i] == id)
            {
                carro.erase(carro.begin() + i);
                printf("Visitante %d saiu no carro\n", id);
                break;
            }
        }

        if (carro.size() == 0)
            esvaziou.notify_all();
    };
};

pthread_barrier_t *barreira;

void passageiro(MonitorMontanhaRussa &montanharussa, int id, int n)
{
    for (int i = 0; i < n; ++i)
    {
        montanharussa.entra_no_carro(id);
        montanharussa.sai_do_carro(id);
        /* Passeia no parque*/

        pthread_barrier_wait(&barreira[i]);
    }

    printf("->>>>>>>> Visitante %d terminou de passear\n", id);
}

void carrinho(MonitorMontanhaRussa &montanharussa, int n)
{
    for (int i = 0; i < n; ++i)
    {
        montanharussa.espera_encher();

        this_thread::yield();
        /* Da Volta*/
        printf("Carrinho deu a volta %d\n", i);

        montanharussa.espera_esvaziar();
    }
}

int main()
{
    MonitorMontanhaRussa montanharussa(CAPACIDADE_CARRO);

    int voltasPorCliente = NUM_VOLTAS / TOTAL_VISITANTES;
    barreira = new pthread_barrier_t[voltasPorCliente];

    for (int i = 0; i < voltasPorCliente; ++i)
        pthread_barrier_init(&barreira[i], NULL, TOTAL_VISITANTES);

    vector<thread> threads;
    for (int i = 0; i < TOTAL_VISITANTES; ++i)
        threads.push_back(thread(passageiro, ref(montanharussa), i, voltasPorCliente));

    threads.push_back(thread(carrinho, ref(montanharussa), NUM_VOLTAS));

    for (thread &p : threads)
        p.join();

    delete[] barreira;

    return 0;
}