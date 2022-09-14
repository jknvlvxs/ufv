#include "Huffman.h"

#include <iostream>
using namespace std;

HuffManTree::HuffManTree(int freqs[256]){
    /* NOTE Ao ser construída, o construtor deverá criar uma árvore de Huffman 
    (que será armazenada na parte privada de HuffManTree) usando o algoritmo descrito anteriormente
    (e obrigatoriamente usando uma fila de prioridades). */
    MyQueue<MySet<int>> priority_queue;

    /* percorre os 256 bytes e caso a frequência seja maior que 0, cria uma árvore para o respectivo símbolo
    após isso, insere a árvore com apenas um nodo em uma fila de prioridades */
    for(int i = 0; i < 256; i++){
        if(freqs[i] != 0){
            MySet<int> caractere;
            caractere.insert(freqs[i], i);
            priority_queue.push(caractere);
        }
    }

    /* NOTE Enquanto o número de árvores não for 1, faça:
        pegue (e as remova da fila) as duas árvores a,b de menor “peso”
        crie uma nova árvore T onde a raiz será um nodo cujo peso é a soma do peso de a e de b. O filho esquerdo de T será a e o direito será b.
        insira T de volta em PQ
    A árvore de Huffman será a (única) árvore restante na fila de prioridades. */
    while(priority_queue.size() > 1){
        MySet<int> arvore_a = priority_queue.top(); priority_queue.pop();
        MySet<int> arvore_b = priority_queue.top(); priority_queue.pop();

        /* inverte as arvores caso uma frequencia seja maior que a outra */
        if((*arvore_b.begin()).first > (*arvore_a.begin()).first) swap(arvore_a, arvore_b);
        /* inverte as árvores caso uma delas seja vazia (soma de outros caracteres) e a outra um caractere */
        if((*arvore_a.begin()).second == '\0' && (*arvore_b.begin()).second != '\0') swap(arvore_a, arvore_b);

        MySet<int> arvore_t;
        arvore_t.merge(arvore_a, arvore_b);
        priority_queue.push(arvore_t);
    }

    if(priority_queue.size() != 0){
        huffman = priority_queue.top();
        huffman.createCodification();
    }
};

/* busca a codificação e adiciona os bits */
void HuffManTree::comprimir(MyVec<bool> &out, const MyVec<unsigned char> &in) const {
    for(MyVec<unsigned char>::iterator it = in.begin(); it != in.end(); it++){
        string huffman_codification = huffman.getCodification(*it); 
        for(int i = 0; i < huffman_codification.size(); i++)
            out.push_back(huffman_codification[i] == '0'? false : true);
    }
};

void HuffManTree::descomprimir(MyVec<unsigned char> &out, const MyVec<bool> &in) const {
    huffman.getCharacter(out, in);
};