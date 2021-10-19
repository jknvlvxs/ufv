#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <string>
#include <fstream>
#include "MyVec.h"
#include "Huffman.h"

using namespace std;

/* função que recebe uma string contendo 8 bits e gera um byte ativando os bits de uma char */
char generateByte(string bits){
    unsigned char byte = 0b00000000;
    for(int i = 0; i < 8; i++)
        if(bits[7-i] == '1')
            byte = byte | 1 << i;
    return byte;
}

/* função que recebe um byte e adiciona todos os bits em um arquivo comprimido */
void generateBits(MyVec<bool> &comprimido, unsigned char byte){
    for (int i = 7; i >= 0; --i)
        comprimido.push_back(((byte >> i) & 0x1));
}

int main(int argc, char**argv) {
    string exec = argv[1];
    string path_read = argv[2];
    string path_write = argv[3];

    fstream in_file, out_file;

    if(exec == "c"){
        in_file.open(path_read, ios::in);
        out_file.open(path_write, ios::out | ios::binary);

        int freqs[256] = {0};
        MyVec<char> in;

        while (!in_file.eof()) {
            char id = in_file.get();
            freqs[id] = ++freqs[id];
            in.push_back(id);
        }
        in_file.close();

        HuffManTree arvore(freqs);

        MyVec<bool> comprimido;
	    arvore.comprimir(comprimido, in);

        /* string que contém a concatenação dos bytes a serem inseridos no arquivo comprimido */
        string binary_out = "";
        /* string com para realizar a soma dos bits e gerar um byte */
        string bits_sum = "";

        /* salva o size (quantidade de bits) no arquivo de saída*/
        int size = comprimido.size();

        if(size != 0){
            out_file.write( reinterpret_cast<char*> (&size), sizeof(int));

            /* salva o as frequências no arquivo de saída*/
            for(int i = 0; i < 256; i++)
                out_file.write( reinterpret_cast<char*> (&freqs[i]), sizeof(int));
        }
        
        /* concatena os bytes na string binary_out */
        for(int i=0; i<comprimido.size(); i++){
            bits_sum += comprimido[i] ? "1" : "0";
            /* a cada 8 bits, gera um byte e concatena na string binary_out */
            if(bits_sum.size() == 8){
                binary_out += generateByte(bits_sum);
                bits_sum = "";
            }

            /* no final da leitura, caso sobrem bits que não forma um byte, adiciona-se 0 e concatena o byte */
            if(comprimido.size()-1 == i && bits_sum.size() > 0 && bits_sum.size() < 8)
                binary_out += generateByte(bits_sum.append(8-bits_sum.size(), '0'));
        }

        out_file.write(binary_out.c_str(), binary_out.size());
        out_file.close();

        // NOTE IMPRIMIR SIZE
        // cout << "size: " << size << endl;

        // NOTE IMPRIMIR FREQUENCIAS
        // for(int i = 0; i < 256; i++){
        //     cout << freqs[i] << endl;
        // }

        // NOTE IMPRIMIR BITS
        // for(int i=0;i<comprimido.size();i++)
        //     cout << comprimido[i];
	    // cout << endl;
    }
    
    if (exec == "d"){
        in_file.open(path_read, ios::in | ios::binary);
        out_file.open(path_write, ios::out);
        
        /* leitura do número de bits*/
        int size;
        in_file.read(reinterpret_cast<char*>(&size), sizeof(int));

        /* leitura das frequências e recriação da árovre de huffman */
        int freqs[256] = {0};
        int id = 0;

        int read_freq;
        while (id < 256) {
            in_file.read(reinterpret_cast<char*>(&read_freq), sizeof(int));
            freqs[id++] = read_freq;
        }

        HuffManTree arvore(freqs);
        
        /* leitura dos bytes */
        MyVec<unsigned char> bytes;
        unsigned char read_byte;
        while (!in_file.eof()) {
            in_file.read(reinterpret_cast<char*>(&read_byte), 1);
            bytes.push_back(read_byte);
        }

        /* com os bytes, é gerado a sequencia de bits e adicionado ao comprimido */
        MyVec<bool> comprimido;
        for(MyVec<unsigned char>::iterator it = bytes.begin(); it != bytes.end(); it++) 
            generateBits(comprimido, *it);

        /* com base no size (quantidade de bits), remove os bits sobressalente */
        while(comprimido.size() > size)
            comprimido.pop_back();

        /* descombrime o conteúdo e insere no arquivo de saída */
        MyVec<char> descomprimido;
        arvore.descomprimir(descomprimido, comprimido);
        for(int i=0;i<descomprimido.size();i++)
            out_file.put(descomprimido[i]);

        in_file.close();
	    out_file.close();

        // NOTE IMPRIMIR SIZE
        // cout << "size: " << size << endl;

        // NOTE IMPRIMIR FREQUENCIAS
        // for(int i = 0; i < 256; i++){
        //     cout << freqs[i] << endl;
        // }

        // NOTE IMPRIMIR BITS
        // for(int i=0;i<comprimido.size();i++)
		//     cout << comprimido[i];
        // cout << endl;
    }
    
/* A seguir, crie um programa main.cpp que usa sua classe para comprimir arquivos. 
Seu programa deverá receber tres argumentos. O primeiro deverá ser “c” ou “d”. 

Se for “c”, ele deverá ler um arquivo (o caminho será o segundo argumento) e gravar
a versão comprimida dele em outro arquivo (o caminho será o terceiro argumento). 

Se o argumento for “d” ele deverá ler um arquivo comprimido (o caminho será o segundo argumento) e gravar
a versão descomprimida em outro arquivo (o caminho será o terceiro argumento).

Por exemplo, “./a.out c wikipediaBrasil.html teste.dat” deverá comprimir wikipediaBrasil.html
(gravando o arquivo comprimido em teste.dat) e “./a.out d teste.dat wikipediaBrasil.html” deverá
restaurar o arquivo (que deverá ficar IDENTICO ao original). Considerando o arquivo wikipediaBrasil.html
(disponível como exemplo), espera-se que o arquivo comprimido tenha em torno de 60% do tamanho do
arquivo original.
*/	
}