#include <iostream>
#include <thread>
#include <mutex>
#include <pthread.h>
#include <map>

using namespace std;

pthread_mutex_t mux = PTHREAD_MUTEX_INITIALIZER;
std::map<pthread_t, int> A;
void block()
{
    bool sair = false;
    long eu = pthread_self();
    do
    {
        pthread_mutex_lock(&mux);
        if (A[eu] > 0)
        {
            A[eu]--;
            sair = true;
        }
        pthread_mutex_unlock(&mux);
    } while (!sair);
}

void wakeup(pthread_t t)
{
    pthread_mutex_lock(&mux);
    A[t]++;
    pthread_mutex_unlock(&mux);
}

// buffer size
#define BUFFER_SIZE 10

// number of items
#define NUM_ITEMS 100

// buffer
int buffer[BUFFER_SIZE];

// utils variables
int contador = 0, in = 0, out = 0;

// the producer thread
void produzir(int dado);

// the consumer thread
void consumir();

// the main function
int main(int argc, char *argv[])
{
    // create the producer thread
    std::thread produtor(produzir, 1);

    // create the consumer thread
    std::thread consumidor(consumir);

    // wait for the producer thread to finish
    produtor.join();

    // wait for the consumer thread to finish
    consumidor.join();

    // exit
    return 0;
}

void printBuffer()
{
    for (int i = 0; i < BUFFER_SIZE; i++)
        cout << buffer[i] << " ";

    cout << endl;
}

// the producer thread
void produzir(int dado)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        block();
        buffer[in] = dado;
        in = (in + 1) % BUFFER_SIZE;
        contador++;
        printBuffer();
        wakeup(pthread_self());
    }
}

// the consumer thread
void consumir()
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        block();
        int dado = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        contador--;
        printBuffer();
        wakeup(pthread_self());
    }
}

// compile with: g++ -o trabalho trabalho.cpp -lpthread
// run with: ./trabalho