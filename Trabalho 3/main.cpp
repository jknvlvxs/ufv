#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <string>
#include <fstream>
#include "MyVec.h"
#include "Huffman.h"

using namespace std;

char generateByte(string bits){
    unsigned char byte = 0b00000000;
    for(int i = 0; i < 8; i++){
        if(bits[7-i] == '1'){
            byte = byte | 1 << i;
        }
    }
    return byte;
}

void generateBits(MyVec<bool> &comprimido, char byte){
    for (int i = 7; i >= 0; --i) {
        comprimido.push_back(((byte >> i) & 0x1));
    }
}

int binary_to_decimal(string& in) {
	int result = 0;
	for (int i = 0; i < in.size(); i++)
		result = result * 2 + in[i] - '0';
	return result;
}


int main(int argc, char**argv) {
    string exec = argv[1];
    string path_read = argv[2];
    string path_write = argv[3];

    fstream in_file, out_file;

    if(exec == "c"){
        int freqs[256] = {0};
        MyVec<char> in;

        in_file.open(path_read, ios::in);
        while (!in_file.eof()) {
            char id = in_file.get();
            freqs[id] = ++freqs[id];
            in.push_back(id);
        }
        in_file.close();

        HuffManTree arvore(freqs);

        MyVec<bool> comprimido;
	    arvore.comprimir(comprimido, in);
        // for(int i=0;i<comprimido.size();i++){
        //     cout << comprimido[i];
            
        // }
	    // cout << endl;

        string binary_out = "";

        string bits_sum = "";

        // cout << "size: " << comprimido.size() << endl;
        binary_out += comprimido.size();

        for(int i=0;i<comprimido.size();i++){
            bits_sum += comprimido[i] ? "1" : "0";
            if(bits_sum.size() == 8){
                // cout << generateByte(bits_sum) << endl;
                binary_out += generateByte(bits_sum);
                bits_sum = "";
            }

            if(comprimido.size()-1 == i && bits_sum.size() > 0 && bits_sum.size() < 8){ // NOTE atenção com final do arquivo para numeros < 8
                bits_sum = bits_sum.append(8-bits_sum.size(), '0');
                binary_out += generateByte(bits_sum);
            }
        }

        for(int i = 0; i < 256; i++){
            binary_out += freqs[i];
        }

        out_file.open(path_write, ios::out | ios::binary);
        out_file.write(binary_out.c_str(), binary_out.size());
        out_file.close();
    }
    
    if (exec == "d"){
        in_file.open(path_read, ios::in | ios::binary);
        out_file.open(path_write, ios::out);
        
        // leitura do numero de bits
        unsigned char size_read;
        in_file.read(reinterpret_cast<char*>(&size_read), 1);
        int size = size_read;	

        // cout << size << endl;

        // leitura dos bytes
        MyVec<unsigned char> text;
        unsigned char textseg;
        // while (!in_file.eof()) {
        for(int arr = 0; arr < size; arr += 8){
            in_file.read(reinterpret_cast<char*>(&textseg), 1);
            text.push_back(textseg);
        }

        // com os bytes, é gerado a sequencia de bits e adicionado a vec comprimido
        MyVec<bool> comprimido;
        for(MyVec<unsigned char>::iterator it = text.begin(); it != text.end(); it++) 
            generateBits(comprimido, *it);

        // cout << endl;

        while(comprimido.size() > size)
            comprimido.pop_back();

        // for(int i=0;i<comprimido.size();i++)
		//     cout << comprimido[i];
        // cout << endl;

        // busca da arvore de huffman
        int freqs[256] = {0};
        int count = 0;

        unsigned char leitura;
        while (!in_file.eof() && count < 256) {
            in_file.read(reinterpret_cast<char*>(&leitura), 1);
            // text.push_back(textseg);
            string teste = "";
            for (int i = 7; i >= 0; --i) {
                teste += (((leitura >> i) & 0x1) == 1 ? '1' : '0');
            }
            freqs[count] = binary_to_decimal(teste);
            count++;
        }

        HuffManTree arvore(freqs);

        string text_out = "";

        MyVec<char> descomprimido;
        arvore.descomprimir(descomprimido, comprimido);
        for(int i=0;i<descomprimido.size();i++)
            out_file.put(descomprimido[i]);
            // text_out += descomprimido[i];
            // cout << descomprimido[i];
        // cout << endl;

        // cout << text_out << endl;

        in_file.close();
	    out_file.close();
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