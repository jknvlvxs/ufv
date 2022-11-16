#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <thread>
#include <semaphore.h>

using namespace std;

#define NUM_CANIBAIS 10

sem_t tem_comida, dormindo, pedacos, mux;

void cozinheiro()
{
    while (true)
    {
        sem_wait(&dormindo);

        int total_a_cozinhar = rand() % 10;
        for (int i = 0; i < total_a_cozinhar; i++)
            sem_post(&pedacos);

        printf("Cozinheiro serviu %d pedaços de comida\n", total_a_cozinhar);
        sem_post(&tem_comida);
    }
}

void canibal(int id)
{
    while (true)
    {
        sem_wait(&mux);
        int pedacos_disponiveis;
        sem_getvalue(&pedacos, &pedacos_disponiveis);

        if (pedacos_disponiveis > 0)
        {
            sem_wait(&pedacos);
            printf("Canibal %d comeu um pedaço de comida. Restam %d pedaço de comida\n", id, pedacos_disponiveis - 1);
            sem_post(&mux);
        }
        else
        {
            sem_post(&dormindo);
            printf("Canibal %d acordou o cozinheiro\n", id);
            sem_wait(&tem_comida);
            sem_post(&mux);
        }
    }
}

int main()
{
    sem_init(&dormindo, 0, 0);
    sem_init(&tem_comida, 0, 0);
    sem_init(&pedacos, 0, 0);
    sem_init(&mux, 0, 1);

    vector<thread> threads;
    threads.push_back(thread(cozinheiro));

    for (int i = 0; i < NUM_CANIBAIS; i++)
        threads.push_back(thread(canibal, i));

    for (thread &t : threads)
        t.join();

    sem_destroy(&dormindo);
    sem_destroy(&tem_comida);
    sem_destroy(&pedacos);
    sem_destroy(&mux);

    return 0;
}