#include "Huffman.h"

#include <iostream>
using namespace std;

HuffManTree::HuffManTree(int freqs[256]){
    /* NOTE Ao ser construída, o construtor deverá criar uma árvore de Huffman 
    (que será armazenada na parte privada de HuffManTree) usando o algoritmo descrito anteriormente
    (e obrigatoriamente usando uma fila de prioridades). */
    MyQueue<MySet<int>> priority_queue;

    for(int i = 0; i < 256; i++){
        if(freqs[i] != 0){
            MySet<int> caractere;
            caractere.insert(freqs[i], i);
            priority_queue.push(caractere);
        }
    }

    cout << endl;

    while(priority_queue.size() > 1){
        // FIXME
        MyQueue<MySet<int>> print_queue = priority_queue;
        while(print_queue.size() > 0){
            print_queue.top().imprimeBFS();
            print_queue.pop();
        }
        cout << endl;

        MySet<int> cr_a = priority_queue.top();
        priority_queue.pop();
        MySet<int> cr_b = priority_queue.top();
        priority_queue.pop();

        if(*cr_b.begin() > *cr_a.begin()) swap(cr_a, cr_b);
        if(cr_a.begin().getCode() == '\0' && cr_b.begin().getCode() != '\0') swap(cr_a, cr_b);

        cout << "a: "; cr_a.imprimeDFS_pre();
        cout << "b: "; cr_b.imprimeDFS_pre();
        cout << endl;

        MySet<int> t;
        t.merge(cr_a, cr_b);

        t.imprimeDFS_pre();
        cout << endl << endl;

        priority_queue.push(t);
    }

    huffman = priority_queue.top();
};

void HuffManTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const {

};

void HuffManTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const {

};