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

    while(priority_queue.size() > 1){
        MySet<int> cr_a = priority_queue.top();
        priority_queue.pop();
        MySet<int> cr_b = priority_queue.top();
        priority_queue.pop();

        if((*cr_b.begin()).first > (*cr_a.begin()).first) swap(cr_a, cr_b);
        if((*cr_a.begin()).second == '\0' && (*cr_b.begin()).first != '\0') swap(cr_a, cr_b);

        MySet<int> t;
        t.merge(cr_a, cr_b);

        priority_queue.push(t);
    }

    if(priority_queue.size() != 0){
        huffman = priority_queue.top();
        huffman.createCodification();
    }
    
};

void HuffManTree::comprimir(MyVec<bool> &out, const MyVec<char> &in) const {
    for(MyVec<char>::iterator it = in.begin(); it != in.end(); it++){
        string huffman_codification = huffman.getCodification(*it); 
        for(int i = 0; i < huffman_codification.size(); i++)
            out.push_back(huffman_codification[i] == '0'? false : true);
    }
};

void HuffManTree::descomprimir(MyVec<char> &out, const MyVec<bool> &in) const {
    huffman.getCharacter(out, in);
};

HuffManTree::HuffManTree(const HuffManTree &other) { 
    *this = other;
}

HuffManTree & HuffManTree::operator=(const HuffManTree &other) {
    if(this==&other) return *this;
    huffman = other.huffman;
    return *this;
}

HuffManTree::~HuffManTree() { 
    // TODO
}
