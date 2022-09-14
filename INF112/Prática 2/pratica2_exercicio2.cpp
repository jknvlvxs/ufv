// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>

using namespace std;

struct Imagem {
    int **pixels;
    int nrows;
    int ncolumns;
};

void leImagem(Imagem &im){
    cin.ignore(2, '\n');
    cin >> im.ncolumns;
    cin >> im.nrows;
    im.pixels = new int *[im.nrows];
    for(int i = 0; i < im.nrows; i++)
        im.pixels[i] = new int[im.ncolumns]; 

    for(int i = 0; i < im.nrows; i++) {
        for(int j = 0; j < im.ncolumns; j++){
            cin >> im.pixels[i][j];
        }
    }
}

void inverteCorImagem(Imagem &im){
    for(int i = 0; i < im.nrows; i++){
        for(int j = 0; j < im.ncolumns; j++){
            if(im.pixels[i][j] == 0) 
                im.pixels[i][j] = 1;
            else if (im.pixels[i][j] == 1) 
                im.pixels[i][j] = 0;
        }
    }
}

void imprimeImagem(Imagem &im){
    cout << "P1" << endl << im.ncolumns << " " << im.nrows << endl;
    for(int i = 0; i < im.nrows; i++) {
        for(int j = 0; j < im.ncolumns; j++){
            cout << im.pixels[i][j];
            if(j < im.ncolumns-1) cout << " ";
        }
        if(i < im.nrows-1) cout << endl;
    }
}

void deletaImagem(Imagem &im){
    for(int i = 0; i < im.nrows; i++) 
        delete[] im.pixels[i]; 
    
    delete[] im.pixels;
}

int main () {
    Imagem im;
    leImagem(im);
    inverteCorImagem(im);
    imprimeImagem(im);
    deletaImagem(im);

    return 0;
}