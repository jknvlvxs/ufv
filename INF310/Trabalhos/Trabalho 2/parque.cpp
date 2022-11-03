#include <mutex>
#include <condition_variable>
#include <thread>
#include <iostream>
#include <vector>

using namespace std;

#define NUM_VOLTAS 1000
#define TAMANHO_CARRO 10
#define TOTAL_VISITANTES 100

class MonitorMontanhaRussa
{
private:
    int totalVoltas;
    vector<int> carro;
    mutex mux;
    condition_variable carro_livre, carro_cheio;
    condition_variable *passageiro;

public:
    MonitorMontanhaRussa(int numPassageiros)
    {
        passageiro = new condition_variable[numPassageiros];
    }

    ~MonitorMontanhaRussa()
    {
        delete[] passageiro;
    }

    void espera_encher()
    {
        unique_lock<mutex> lck(mux);

        while (carro.size() < TAMANHO_CARRO)
            carro_livre.wait(lck);

        carro_cheio.notify_all();
    };

    void espera_esvaziar()
    {
        unique_lock<mutex> lck(mux);

        while (carro.size() > 0)
            carro_cheio.wait(lck);

        carro_livre.notify_all();
    };

    void entra_no_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        while (carro.size() >= TAMANHO_CARRO)
            carro_cheio.wait(lck);

        printf("Visitante %d entrou no carro\n", id);
        carro.push_back(id);
        passageiro[id].wait(lck);
        carro_livre.notify_one();
    };

    void sai_do_carro(int id)
    {
        unique_lock<mutex> lck(mux);

        while (carro.size() <= 0)
            carro_livre.wait(lck);

        printf("Visitante %d saiu no carro\n", id);

        carro_cheio.notify_all();
        passageiro[id].notify_one();
    };
};

void passageiro(MonitorMontanhaRussa &montanharussa, int id, int n)
{
    for (int i = 0; i < n; ++i)
    {
        montanharussa.entra_no_carro(id);
        montanharussa.sai_do_carro(id);
        /* Passeia no parque*/
    }
}

void carrinho(MonitorMontanhaRussa &montanharussa, int n)
{
    for (int i = 0; i < n; ++i)
    {
        montanharussa.espera_encher();

        /* Da Volta*/
        printf("Carrinho deu a volta %d", i);

        montanharussa.espera_esvaziar();
    }
}

int main()
{
    MonitorMontanhaRussa montanharussa(TAMANHO_CARRO);

    vector<thread> passageiros;
    for (int i = 0; i < TOTAL_VISITANTES; ++i)
        passageiros.push_back(thread(passageiro, ref(montanharussa), i, NUM_VOLTAS / TOTAL_VISITANTES));

    thread carro = thread(carrinho, ref(montanharussa), NUM_VOLTAS);

    for (thread &p : passageiros)
        p.join();

    carro.join();

    return 0;
}