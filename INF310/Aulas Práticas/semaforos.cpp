#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <thread>
#include <semaphore.h>

using namespace std;

#define NUM_PACIENTES 10
#define NUM_DOSES 2
#define TIPOS_VACINAS 3

int pacientes[NUM_PACIENTES];
sem_t vacinas[TIPOS_VACINAS], vazios;
int vac1[TIPOS_VACINAS], vac2[TIPOS_VACINAS];

void aplica(int id){
    for(int i = 0; i < NUM_DOSES; i++){
        if(i == 0){
            sem_wait(&vazios);
            int b = 0;
            for(b = 0; b < TIPOS_VACINAS; b++)
                if(vac1[b] > 0) break;
            pacientes[id] = b;
            vac1[b]--;
            printf("Paciente %d tomou %dª dose da vacina %d\n", id, i+1, b);
        } else {
            int b = pacientes[id];
            sem_wait(&vacinas[b]);
            vac2[b]--;
            printf("Paciente %d tomou %dª dose da vacina %d\n", id, i+1, b);
        }
    }
}

void produz(){
    for(int i = 0; i < NUM_PACIENTES; i++){
        int b = rand() % TIPOS_VACINAS;
        vac1[b]++;
        vac2[b]++;
        printf("Produziu vacina %d\n", b);
        sem_post(&vazios);
        sem_post(&vacinas[b]);
    }
}

int main () {
    sem_init(&vazios,0,0);

    for(int i=0; i<TIPOS_VACINAS; ++i)
        sem_init(&vacinas[i],0,0); 

    vector<thread> pacientes;
    for (int i = 0; i < NUM_PACIENTES; i++)
    {
        pacientes.push_back(thread(aplica, i));
    }

    thread pro = thread(produz);

    for (thread &pac : pacientes)
        pac.join();

    pro.join();

    for(int i=0; i<TIPOS_VACINAS; ++i)
        sem_destroy(&vacinas[i]);

    sem_destroy(&vazios);

    return 0;
}