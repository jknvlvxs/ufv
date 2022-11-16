#include <iostream>
#include <thread>
#include <semaphore.h>

using namespace std;

int x = 0;

sem_t mux, menor, maior;

void thread_A()
{
    while (true)
    {
        sem_wait(&maior);
        sem_wait(&mux);

        x += 1;
        printf("A: %d\n", x);

        sem_post(&menor);
        sem_post(&mux);
    }
}

void thread_B()
{
    while (true)
    {
        sem_wait(&menor);
        sem_wait(&mux);

        x -= 1;
        printf("B: %d\n", x);

        sem_post(&maior);
        sem_post(&mux);
    }
}

int main()
{
    sem_init(&mux, 0, 1);
    sem_init(&menor, 0, 0);
    sem_init(&maior, 0, 10);

    thread t1(thread_A);
    thread t2(thread_B);

    t1.join();
    t2.join();

    sem_destroy(&mux);
    sem_destroy(&menor);
    sem_destroy(&maior);

    return 0;
}