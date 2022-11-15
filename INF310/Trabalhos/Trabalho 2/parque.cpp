#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

#define NUM_VOLTAS 1000
#define CAPACIDADE_CARRO 10
#define TOTAL_CLIENTES 100

class MonitorMontanhaRussa
{
private:
    mutex mux;
    condition_variable carro_livre, carro_cheio;
    condition_variable encheu, esvaziou;

    vector<int> carro;
    int capacidade_carro;
    bool dando_voltas = false, esvaziando = false;

public:
    MonitorMontanhaRussa(int capacidade)
    {
        capacidade_carro = capacidade;
    }

    void espera_encher()
    {
        unique_lock<mutex> lck(mux);

        dando_voltas = false;

        carro_livre.notify_all();

        encheu.wait(lck, [this]
                    { return carro.size() == capacidade_carro; });

        dando_voltas = true;
        printf("Carro cheio\n");
    };

    void espera_esvaziar()
    {
        unique_lock<mutex> lck(mux);

        dando_voltas = false;
        esvaziando = true;

        carro_cheio.notify_all();

        esvaziou.wait(lck, [this]
                      { return carro.size() == 0; });

        esvaziando = false;
        printf("Carro vazio\n");
    };

    void entra_no_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        carro_livre.wait(lck, [this]
                         { return carro.size() < capacidade_carro && !dando_voltas && !esvaziando; });

        carro.push_back(id);
        printf("Visitante %d entrou no carro\n", id);

        if (carro.size() == capacidade_carro)
            encheu.notify_all();
    };

    void sai_do_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        carro_cheio.wait(lck, [this]
                         { return carro.size() > 0 && !dando_voltas && esvaziando; });

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

void carro(MonitorMontanhaRussa &montanharussa, int n)
{
    for (int i = 0; i < n; ++i)
    {
        montanharussa.espera_encher();

        /* Da Volta*/
        printf("Carrinho deu a volta %d\n", i + 1);

        montanharussa.espera_esvaziar();
    }
}

void cliente(MonitorMontanhaRussa &montanharussa, int id, int n)
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

int main()
{
    MonitorMontanhaRussa montanharussa(CAPACIDADE_CARRO);

    int voltasPorCliente = NUM_VOLTAS / CAPACIDADE_CARRO;
    barreira = new pthread_barrier_t[voltasPorCliente];

    for (int i = 0; i < voltasPorCliente; ++i)
        pthread_barrier_init(&barreira[i], NULL, TOTAL_CLIENTES);

    vector<thread> threads;
    threads.push_back(thread(carro, ref(montanharussa), NUM_VOLTAS));

    for (int i = 0; i < TOTAL_CLIENTES; ++i)
        threads.push_back(thread(cliente, ref(montanharussa), i, voltasPorCliente));

    for (thread &p : threads)
        p.join();

    delete[] barreira;

    return 0;
}