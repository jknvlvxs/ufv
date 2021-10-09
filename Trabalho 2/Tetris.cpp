#include "Tetris.h"

#include <iostream>
using namespace std;

Tetris::Tetris(int c) {
    create(c);
}

//Construtor de cópia - copia recurso
Tetris::Tetris(const Tetris &other) { 
    create(other.largura);
    *this = other;
}

Tetris & Tetris::operator=(const Tetris &other) {
	if(this==&other) return *this;
    clear();

    largura = other.largura;
    jogo = new char *[other.largura];
    alturas = new int[other.largura];

    // laço para preencher o jogo cópia com os dados do jogo raiz
    for(int i = 0; i < other.largura; i++) {
        alturas[i] = other.alturas[i];
        jogo[i] = new char[other.alturas[i]];
        for(int j = 0; j < other.alturas[i]; j++){
            jogo[i][j] = other.jogo[i][j];
        }
    } 

    return *this;
}

// função para criar um jogo vazio
void Tetris::create(int c){
    largura = c;
    jogo = new char *[largura];
    alturas = new int[largura];

    for(int i = 0; i < largura; i++){
        jogo[i] = new char[0];
        alturas[i] = 0;
    }
}

// função para realizar a deleção jogo
void Tetris::clear(){
    for (int i=0; i<largura; i++)
        delete[] jogo[i];
    
    delete[] jogo;
    delete[] alturas;
}

char Tetris::get(int c, int l) const {
    if(alturas[c] > l) // verifica se l está dentro de alturas[c] (garante que [c][l] está inicializado)
        if(jogo[c][l] == 'I' || jogo[c][l] == 'O' || jogo[c][l] == 'J' || jogo[c][l] == 'L' || jogo[c][l] == 'S' || jogo[c][l] == 'Z' || jogo[c][l] == 'T')
            return jogo[c][l];
    
    return ' '; // caso não esteja inicializado ou não possua peça, retorna vazio
}

int Tetris::getNumColunas() const {
    return largura;
}

int Tetris::getAltura(int c) const {
    return alturas[c];
}

int Tetris::getAltura() const {
    int maiorAltura = alturas[0];    

    for(int i = 1; i < largura; i++)
        if(alturas[i] > maiorAltura) maiorAltura = alturas[i];

    return maiorAltura;
}

void Tetris::removeColuna(int c){
    // cria um novo_jogo e uma nova_altura com largura menor
    char **novo_jogo = new char*[largura-1];
    int *nova_altura = new int[largura-1];

    // inicializa novo_jogo e nova_altura com os valores antigos de jogo e alturas
    for(int i = 0; i < largura-1; i++){
        // para os valores anteriores a coluna, se mantem o mesmo
        // para os valores a partir da coluna, ele recebe o valor da coluna a direita
        if(i < c) nova_altura[i] = alturas[i];
        if(i >= c) nova_altura[i] = alturas[i+1];

        novo_jogo[i] = new char[nova_altura[i]];
        
        for(int j = 0; j < nova_altura[i]; j++){
            if(i < c) novo_jogo[i][j] = jogo[i][j];
            if(i >= c) novo_jogo[i][j] = jogo[i+1][j];
        }
    }

    clear();

    // cria jogo e alturas, agora com o novo tamanho de colunas
    jogo = new char *[largura-1];
    alturas = new int[largura-1];

    // inicializa jogo e alturas com os valores em novo_jogo e nova_altura
    for(int i = 0; i < largura-1; i++){
        alturas[i] = nova_altura[i];
        jogo[i] = new char[nova_altura[i]];
        for(int j = 0; j < nova_altura[i]; j++){
            jogo[i][j] = novo_jogo[i][j];
        }
    }

    // deleta os arrays auxiliares de novo_jogo e nova_altura
    for (int i=0; i<largura-1; i++)
        delete[] novo_jogo[i];
    
    delete[] novo_jogo;
    delete[] nova_altura;

    // subtrai o valor da largura
    largura--;
}


void Tetris::removeLinhasCompletas(){
    // busca a menor altura que todas as colunas tem em comum
    int menorAltura = alturas[0];    

    for(int i = 1; i < largura; i++)
        if(alturas[i] < menorAltura) menorAltura = alturas[i];

    for(int i = menorAltura-1; i >= 0; i--){
        bool deletar_linha = true;
            
        // laço que percorre as colunas para verificar se todas as colunas de determinada linha estão preenchidas        
        for(int j = 0; j < largura; j++)
            if(get(j, i) == ' ') deletar_linha = false;
            
        // caso todas as colunas da linha estejam preenchidas, deve-se eliminar a linha            
        if(deletar_linha){
            for(int c = 0; c < largura; c++){
                char *aux = jogo[c];
                jogo[c] = new char[alturas[c]-1];   

                for(int k = 0; k < alturas[c]-1; k++){
                    if(k < i) jogo[c][k] = aux[k];
                    if(k >= i) jogo[c][k] = aux[k+1];
                }
                
                delete[] aux;

                alturas[c]--;
                corrigeAltura(c);
            }
        }
    }
}

// função que inicializa a coluna com o tamanho necessário, incializa e preenche ela com seu valor antigo
void Tetris::preencheColuna(int c, int l){
    if(l > alturas[c]) {
        char *aux = jogo[c];
        jogo[c] = new char[l];

        for(int i = 0; i < l; i++)
            jogo[c][i] = ' ';
                
        for(int i = 0; i < alturas[c]; i++)
            jogo[c][i] = aux[i];

        delete[] aux;
    }
}

// função que verifica se a peça pode ser inserida na posição [c][l], caso sim, retorna true
bool Tetris::verificaPeca(int c, int l){
    // verifica as dimenções de c
    if(c >= largura)
        return false;

    // verifica as dimenções de l
    if(l < 0)
        return false;        

    // verifica se [c][l] está vazio
    if(get(c,l) != ' ')
        return false;

    return true;
}

// função para corrigir a array de alturas, para os casos de remoção de linha ou de inserção não permitida
void Tetris::corrigeAltura(int c){
    // verifica se a altura foi corrigida, caso não, significa que não há nenhuma peça e a altura é 0
    bool altura_corrigida = false;

    for(int i = getAltura(c); i >= 0; i--){
        // verifica a primeira linha onde existe uma peça e atribui a altura daquela coluna
        if(get(c,i) != ' '){
            alturas[c] = i+1;
            altura_corrigida = true;
            break;
        }
    }

    if(!altura_corrigida){
        char *aux = jogo[c];
        jogo[c] = new char[0];   
        delete[] aux;
        alturas[c] = 0;
    };
}

bool Tetris::adicionaForma(int c, int l, char id, int rotacao){
    l++;    

    if(c < 0) return false;

    /* INICIALIZAR COLUNA
        Segui a seguinte lógica: Verifiquei cada uma das peças, e entendi que cada uma dela, poderá utilizar de 1 a 4 colunas.
        Dessa forma, fiz um if pra abrangir cada uma dessas possibilizadas, e inicializei a quantidade de colunas necessárias.
        Ex: para inserir um I em 180° necessita-se de 1 coluna, porém, para inserir um I em 90° necessita-se de 4.
    */

    // INICIALIZAR CASOS DE 1 COLUNA
    if(id == 'I' && (rotacao == 0 || rotacao == 180)){
        if(c >= largura) return false;

        preencheColuna(c, l);
        alturas[c] = l;
    }

    // INICIALIZAR CASOS DE 2 COLUNAS
    if(id == 'O' || ((id != 'I') && (rotacao == 90 || rotacao == 270))){
        if(c >= largura) return false;
        if(c+1 >= largura) return false;

        preencheColuna(c, l);
        preencheColuna(c+1, l);

        if(id == 'O' || (id == 'J' && rotacao == 270) || (id == 'L' && rotacao == 90)){
            if(l > alturas[c]) alturas[c] = l;
            if(l > alturas[c+1]) alturas[c+1] = l;
        }

        if(id == 'S' || (id == 'T' && rotacao == 270)){
            if(l > alturas[c]) alturas[c] = l;
            if(l-1 > alturas[c+1]) alturas[c+1] = l-1;
        }

        if(id == 'Z' || (id == 'T' && rotacao == 90)){
            if(l-1 > alturas[c]) alturas[c] = l-1;
            if(l > alturas[c+1]) alturas[c+1] = l;
        }

        if((id == 'J' && rotacao == 90)){
            if(l-3 > alturas[c]) alturas[c] = l-3;
            if(l > alturas[c+1]) alturas[c+1] = l;
        }

        if((id == 'L' && rotacao == 270)){
            if(l > alturas[c]) alturas[c] = l;
            if(l-3 > alturas[c+1]) alturas[c+1] = l-3;
        }
    }

    // INICIALIZAR CASOS DE 3 COLUNAS
    if(((id == 'S' || id == 'Z' || id == 'T') && (rotacao == 0 || rotacao == 180))){
        if(c >= largura) return false;
        if(c+1 >= largura) return false;
        if(c+2 >= largura) return false;

        preencheColuna(c, l);
        preencheColuna(c+1, l);
        preencheColuna(c+2, l);

        if(id == 'S'){
            if(l-1 > alturas[c]) alturas[c] = l-1;
            if(l > alturas[c+1]) alturas[c+1] = l;
            if(l > alturas[c+2]) alturas[c+2] = l;
        }

        if(id == 'Z'){
            if(l > alturas[c]) alturas[c] = l;
            if(l > alturas[c+1]) alturas[c+1] = l;
            if(l-1 > alturas[c+2]) alturas[c+2] = l-1;
        }

        if(id == 'T' && rotacao == 0){
            if(l > alturas[c]) alturas[c] = l;
            if(l > alturas[c+1]) alturas[c+1] = l;
            if(l > alturas[c+2]) alturas[c+2] = l;
        }

        if (id == 'T' && rotacao == 180){
            if(l-1 > alturas[c]) alturas[c] = l-1;
            if(l > alturas[c+1]) alturas[c+1] = l;
            if(l-1 > alturas[c+2]) alturas[c+2] = l-1;
        }
    }

    // INICIALIZAR CASOS DE 4 COLUNAS
    if((id == 'I' && (rotacao == 90 || rotacao == 270)) || ((id == 'J' || id == 'L') && (rotacao == 0 || rotacao == 180))){
        if(c >= largura) return false;
        if(c+1 >= largura) return false;
        if(c+2 >= largura) return false;
        if(c+3 >= largura) return false;

        preencheColuna(c, l);
        preencheColuna(c+1, l);
        preencheColuna(c+2, l);  
        preencheColuna(c+3, l);

        if(id == 'I' || rotacao == 0){
            if(l > alturas[c]) alturas[c] = l;
            if(l > alturas[c+1]) alturas[c+1] = l;
            if(l > alturas[c+2]) alturas[c+2] = l;
            if(l > alturas[c+3]) alturas[c+3] = l;
        }

        if(id == 'J' && rotacao == 180){
            if(l > alturas[c]) alturas[c] = l;
            if(l-1 > alturas[c+1]) alturas[c+1] = l-1;
            if(l-1 > alturas[c+2]) alturas[c+2] = l-1;
            if(l-1 > alturas[c+3]) alturas[c+3] = l-1;
        }

        if(id == 'L' && rotacao == 180) {
            if(l-1 > alturas[c]) alturas[c] = l-1;
            if(l-1 > alturas[c+1]) alturas[c+1] = l-1;
            if(l-1 > alturas[c+2]) alturas[c+2] = l-1;
            if(l > alturas[c+3]) alturas[c+3] = l;
        }
    }

    l--;

    /* ADICIONAR PEÇA
        Em seguida, mapeei cada uma das peças e criei um if para abranger cada tipo de peça.
        Dentro de cada if, ele verifica se cada uma das posições da peça estão livres, caso sim, insere a peça e retorna true
        Caso uma das posições não permita inserção, ele corrige a altura e retorna false.
    */
    
    // ADICIONAR PEÇA I0 E I180
    if(id == 'I' && (rotacao == 0 || rotacao == 180)){
        //[C][L], [C][L-1], [C][L-2], [C][L-3]
        if(verificaPeca(c,l) && verificaPeca(c,l-1) && verificaPeca(c,l-2) && verificaPeca(c,l-3)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c][l-2] = id;
            jogo[c][l-3] = id;
            return true;
        }

        corrigeAltura(c);
        return false;
    }

    // ADICIONAR PEÇA I90 E I270
    if(id == 'I' && (rotacao == 90 || rotacao == 270)){
        //[C][L], [C+1][L], [C+2][L], [C+3][L]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+2,l) && verificaPeca(c+3,l)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+2][l] = id;
            jogo[c+3][l] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        corrigeAltura(c+3);
        return false;
    }

    // ADICIONAR PEÇA O0, O90, O180 E O270
    if(id == 'O'){
        //[C][L], [C][L-1], [C+1][L], [C+1][L-1]
        if(verificaPeca(c,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l) && verificaPeca(c+1,l-1)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l] = id;
            jogo[c+1][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA J0
    if(id == 'J' && rotacao == 0){
        //[C][L], [C+1][L], [C+2][L], [C+3][L], [C+3][L-1]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+2,l) && verificaPeca(c+3,l) && verificaPeca(c+3,l-1)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+2][l] = id;
            jogo[c+3][l] = id;
            jogo[c+3][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        corrigeAltura(c+3);
        return false;
    }

    //ADICIONAR PEÇA J90
    if(id == 'J' && rotacao == 90){
        //[C+1][L], [C+1][L-1], [C+1][L-2], [C+1][L-3], [C][L-3]
        if(verificaPeca(c+1,l) && verificaPeca(c+1,l-1) && verificaPeca(c+1,l-2) && verificaPeca(c+1,l-3) && verificaPeca(c,l-3)){
            jogo[c+1][l] = id;
            jogo[c+1][l-1] = id;
            jogo[c+1][l-2] = id;
            jogo[c+1][l-3] = id;
            jogo[c][l-3] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA J180
    if(id == 'J' && rotacao == 180){
        //[C][L], [C][L-1], [C+1][L-1], [C+2][L-1], [C+3][L-1]
        if(verificaPeca(c,l) && verificaPeca(c,l-1)&&verificaPeca(c+1,l-1) && verificaPeca(c+2,l-1) && verificaPeca(c+3,l-1)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c+2][l-1] = id;
            jogo[c+3][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        corrigeAltura(c+3);
        return false;
    }

    //ADICIONAR PEÇA J270
    if(id == 'J' && rotacao == 270){
        //[C][L], [C+1][L], [C][L-1], [C][L-2], [C][L-3]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c,l-1) && verificaPeca(c,l-2) && verificaPeca(c,l-3)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c][l-1] = id;
            jogo[c][l-2] = id;
            jogo[c][l-3] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA L0
    if(id == 'L' && rotacao == 0){
        //[C][L], [C+1][L], [C+2][L], [C+3][L], [C][L-1]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+2,l) && verificaPeca(c+3,l) && verificaPeca(c,l-1)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+2][l] = id;
            jogo[c+3][l] = id;
            jogo[c][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        corrigeAltura(c+3);
        return false;
    }

    //ADICIONAR PEÇA L90
    if(id == 'L' && rotacao == 90){
        //[C][L], [C+1][L], [C+1][L-1], [C+1][L-2], [C+1][L-3]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+1,l-1) && verificaPeca(c+1,l-2) && verificaPeca(c+1,l-3)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+1][l-1] = id;
            jogo[c+1][l-2] = id;
            jogo[c+1][l-3] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA L180
    if(id == 'L' && rotacao == 180){
        //[C+3][L], [C][L-1], [C+1][L-1], [C+2][L-1], [C+3][L-1]
        if(verificaPeca(c+3,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l-1) && verificaPeca(c+2,l-1) && verificaPeca(c+3,l-1)){
            jogo[c+3][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c+2][l-1] = id;
            jogo[c+3][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        corrigeAltura(c+3);
        return false;
    }

    //ADICIONAR PEÇA L270
    if(id == 'L' && rotacao == 270){
        //[C][L], [C][L-1], [C][L-2], [C][L-3], [C+1][L-1]
        if(verificaPeca(c,l) && verificaPeca(c,l-1) && verificaPeca(c,l-2) && verificaPeca(c,l-3) && verificaPeca(c+1,l-3)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c][l-2] = id;
            jogo[c][l-3] = id;
            jogo[c+1][l-3] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA S0 E S180
    if(id == 'S' && (rotacao == 0 || rotacao == 180)){
        //[C+1][L], [C+2][L], [C][L-1], [C+1][L-1]
        if(verificaPeca(c+1,l) && verificaPeca(c+2,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l-1)){
            jogo[c+1][l] = id;
            jogo[c+2][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        return false;
    }

    //ADICIONAR PEÇA S90 E S270
    if(id == 'S' && (rotacao == 90 || rotacao == 270)){
        //[C][L], [C][L-1], [C+1][L-1], [C+1][L-2]
        if(verificaPeca(c,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l-1) && verificaPeca(c+1,l-2)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c+1][l-2] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA Z0 E Z180
    if(id == 'Z' && (rotacao == 0 || rotacao == 180)){
        //[C][L], [C+1][L], [C+1][L-1], [C+2][L-1]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+1,l-1) && verificaPeca(c+2,l-1)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+1][l-1] = id;
            jogo[c+2][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        return false;
    }

    //ADICIONAR PEÇA Z90 E Z270
    if(id == 'Z' && (rotacao == 90 || rotacao == 270)){
        //[C+1][L], [C][L-1], [C+1][L-1], [C][L-2]
        if(verificaPeca(c+1,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l-1) && verificaPeca(c,l-2)){
            jogo[c+1][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c][l-2] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA T0
    if(id == 'T' && rotacao == 0){
        //[C][L], [C+1][L], [C+2][L], [C+1][L-1]
        if(verificaPeca(c,l) && verificaPeca(c+1,l) && verificaPeca(c+2,l) && verificaPeca(c+1,l-1)){
            jogo[c][l] = id;
            jogo[c+1][l] = id;
            jogo[c+2][l] = id;
            jogo[c+1][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        return false;
    }

    //ADICIONAR PEÇA T90
    if(id == 'T' && rotacao == 90){
        //[C+1][L], [C][L-1], [C+1][L-1], [C+1][L-2]
        if(verificaPeca(c+1,l) && verificaPeca(c,l-1) && verificaPeca(c+1, l-1) && verificaPeca(c+1,l-2)){
            jogo[c+1][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c+1][l-2] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    //ADICIONAR PEÇA T180
    if(id == 'T' && rotacao == 180){
        //[C+1][L], [C][L-1], [C+1][L-1], [C+2][L-1]
        if(verificaPeca(c+1,l) && verificaPeca(c,l-1) && verificaPeca(c+1,l-1) && verificaPeca(c+2,l-1)){
            jogo[c+1][l] = id;
            jogo[c][l-1] = id;
            jogo[c+1][l-1] = id;
            jogo[c+2][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        corrigeAltura(c+2);
        return false;
    }

    //ADICIONAR PEÇA T270
    if(id == 'T' && rotacao == 270){
        //[C][L], [C][L-1], [C][L-2], [C+1][L-1] 
        if(verificaPeca(c,l) && verificaPeca(c,l-1) && verificaPeca(c,l-2) && verificaPeca(c+1,l-1)){
            jogo[c][l] = id;
            jogo[c][l-1] = id;
            jogo[c][l-2] = id;
            jogo[c+1][l-1] = id;
            return true;
        }

        corrigeAltura(c);
        corrigeAltura(c+1);
        return false;
    }

    return false;
}

Tetris::~Tetris(){
    clear();
}

/* MAPEAMENTO DAS PEÇAS
I
0 & 180 -> [C][L], [C][L-1], [C][L-2], [C][L-3]
90 & 270 ->  [C][L], [C+1][L], [C+2][L], [C+3][L]

O
O & 90 & 180 & 270 -> [C][L], [C][L-1], [C+1][L], [C+1][L-1]

J
0 -> [C][L], [C+1][L], [C+2][L], [C+3][L], [C+3][L-1]
90 -> [C+1][L], [C+1][L-1], [C+1][L-2], [C+1][L-3], [C][L-3]
180 -> [C][L], [C][L-1], [C+1][L-1], [C+2][L-1], [C+3][L-1]
270 -> [C][L], [C+1][L], [C][L-1], [C][L-2], [C][L-3]

L
0 -> [C][L], [C+1][L], [C+2][L], [C+3][L], [C][L-1]
90 -> [C][L], [C+1][L], [C+1][L-1], [C+1][L-2], [C+1][L-3]
180 -> [C+3][L], [C][L-1], [C+1][L-1], [C+2][L-1], [C+3][L-1]
270 -> [C][L], [C][L-1], [C][L-2], [C][L-3], [C+1][L-1]

S
0 & 180 -> [C+1][L], [C+2][L], [C][L-1], [C+1][L-1]
90 & 270 -> [C][L], [C][L-1], [C+1][L-1], [C+1][L-2]

Z
0 & 180 -> [C][L], [C+1][L], [C+1][L-1], [C+2][L-1]
90 & 270 -> [C+1][L], [C][L-1], [C+1][L-1], [C][L-2]

T
0 -> [C][L], [C+1][L], [C+2][L], [C+1][L-1]
90 -> [C+1][L], [C][L-1], [C+1][L-1], [C+1][L-2]
180 -> [C+1][L], [C][L-1], [C+1][L-1], [C+2][L-1]
270 -> [C][L], [C][L-1], [C][L-2], [C+1][L-1] 
*/