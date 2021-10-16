// classe HuffManTree 
#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "MyVec.h"
#include "MySet.h"
#include "MyQueue.h"

class HuffManTree {
    private:
        // TODO criar uma árvore de Huffman
        MySet<int> huffman;
    public:
        /* NOTE Sua classe deverá ter um construtor que recebe como argumento um array automático
        com a frequência dos 256 possíveis símbolos em um byte (“HuffManTree(int freqs[256])”). */
        HuffManTree(int freqs[256]);

        //TODO não esquecer construtor de cópia, operador de atribuição e destrutor
        
        
        /* NOTE Essa função deverá ler o vetor de bytes (chars) “in”, comprimi-lo e gravar os bits
        representando o arquivo comprimido em “out” (cada bool de out representará um bit , sendo 1
        representado por true e 0 por false)*/
        void comprimir(MyVec<bool> &out, const MyVec<char> &in) const;

        /* NOTE Essa função deverá fazer o inverso do que a função acima faz. */
        void descomprimir(MyVec<char> &out, const MyVec<bool> &in) const;
};

#endif