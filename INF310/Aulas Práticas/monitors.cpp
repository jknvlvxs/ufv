#include <mutex>
#include <condition_variable>
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

mutex mux;
int copo = -1;
int *bebeu = new int[3];
bool fimFesta = false;
condition_variable copoLivre, copoCheio;


void setFimFesta(bool fim) {
    fimFesta = fim;
    copoCheio.notify_all();
}

void serve(int b) {
    unique_lock<mutex> lck(mux);

    while(copo != -1) copoLivre.wait(lck);
    
    copo = b;
    cout << "Serviu " << copo << endl;
    copoCheio.notify_all();
}

bool bebe(int c) {
    unique_lock<mutex> lck(mux);

    
    while((copo == -1 || copo > c) && !fimFesta) copoCheio.wait(lck);

    if(fimFesta) {
        cout << "Convidado " << c << " bebeu " << bebeu[c] << endl;
        return false;
    } else {
        cout << "Bebeu " << c << endl;
        copo = -1;
        ++bebeu[c];
        copoLivre.notify_one();
        return true;
    }
}

void garcom(){
    for (int i=0; i<1000; ++i) {
        int b = rand() % 3;
        serve(b);
    }

    setFimFesta(true);
};

void convidado(int c){
    while(bebe(c));
};

int main(){
    // 1 -> 1/3 * 1/3
    // 2 -> 1/3 * 1/3 + 1/3 * 1/2
    // 3 -> 1/3 * 1/3 + 1/3 * 1/2 + 1/3

    vector<thread> convidados;
    for(int i = 0; i < 3; i++){
        convidados.push_back(thread(convidado, i));
    }

    thread g = thread(garcom);

    for(thread &c: convidados)
        c.join();
    
    g.join();


    return 0;
};