#include <iostream>
#include "Tetris.h"

using namespace std;

void exibeTabela(Tetris &game) {
    cout << "------------------------------------------------" << endl;
    int max_size = 16;
    for(int i = 0; i < max_size; i++){
        for(int j = 0; j < game.getNumColunas(); j++){
            cout << game.get(j, max_size-i-1);;
        }
        cout << endl;
    }
    cout << "===============================================" << endl;
}

void exibeJogo(Tetris &game) {
    cout << "------------------------------------------------" << endl;
    for(int i = game.getAltura()-1; i >=0 ; i--){
        for(int j = 0; j < game.getNumColunas(); j++){
            cout << game.get(j, i);;
        }
        cout << endl;
    }
    cout << "------------------------------------------------" << endl;
}

void exibeAlturas(Tetris &game) {
    for(int i = 0; i < game.getNumColunas(); i++)
        cout << game.getAltura(i);
    cout << endl;
    cout << "===============================================" << endl;
}

void exibeLargura(Tetris &game){
    cout << "altura: " << game.getAltura() << " ";
    cout << "colunas: " << game.getNumColunas() << endl;
}

void exibe(Tetris &game){
    exibeLargura(game);
    exibeJogo(game);
    exibeAlturas(game);
}

int main() {
    /*Test 6
        Tetris game6(15);
        exibe(game6);
        
        game6.adicionaForma(0, 0, 'O', 0);
        game6.adicionaForma(14, 0, 'O', 0);
        game6.adicionaForma(5, 0, 'O', 0);
        game6.adicionaForma(200, 200, 'O', 0);
        game6.adicionaForma(200, 0, 'O', 0);

        exibe(game6);

        game6.removeLinhasCompletas();
        game6.removeColuna(0);
        game6.removeColuna(1);
        game6.removeColuna(0);
        game6.removeColuna(11);

        exibe(game6);
    */

    /* Test 7
    */
        Tetris game7(17);
        exibe(game7);

        game7.adicionaForma(0, 0, 'I', 270);
        exibe(game7);

        game7.removeLinhasCompletas();
        game7.removeColuna(16);
        exibe(game7);

        game7.adicionaForma(0, 1, 'I', 90);
        game7.adicionaForma(4, 0, 'I', 90);
        game7.adicionaForma(8, 0, 'I', 90);
        game7.adicionaForma(12, 0, 'I', 90);
        exibe(game7);

        game7.adicionaForma(4, 1, 'I', 90);
        game7.adicionaForma(8, 1, 'I', 90);
        game7.adicionaForma(12, 1, 'I', 90);
        exibe(game7);

        game7.adicionaForma(0, 2, 'I', 90);
        game7.adicionaForma(4, 2, 'I', 90);
        game7.adicionaForma(8, 2, 'I', 90);
        game7.adicionaForma(12, 2, 'I', 90);
        game7.adicionaForma(8, 3, 'I', 90);
        game7.adicionaForma(0, 4, 'I', 90);
        game7.adicionaForma(4, 4, 'I', 90);
        game7.adicionaForma(8, 4, 'I', 90);
        game7.adicionaForma(12, 4, 'I', 90);
        exibe(game7);
        
        game7.adicionaForma(10, 5, 'I', 90);
        game7.adicionaForma(1, 5, 'I', 90);
        exibe(game7);

        game7.removeLinhasCompletas();
        exibe(game7);

    /*Test 11
        Tetris game11(9);
        game11.adicionaForma(0, 5, 'I', 270);
        game11.adicionaForma(2, 4, 'I', 270);
        game11.adicionaForma(1, 2, 'I', 270);
        game11.adicionaForma(0, 4, 'Z', 90);
        // exibe(game11);
        

        game11.adicionaForma(5, 2, 'O', 270);
        game11.adicionaForma(7, 2, 'O', 270);
        game11.removeLinhasCompletas();
        exibe(game11);

        // exibe(game11);
        
        // exibe(game11);
        // Tetris game12 = game11;
        // game12.adicionaForma(7, 8, 'O', 270);
        // exibe(game12);
        // Tetris game13(12);
        // game13 = game12;
        // game13.removeLinhasCompletas();
        // exibe(game13);
    */
    
    /*Test 12 
    Tetris game12(20);
    // game12.adicionaForma(0, 5, 'I', 0);
    // game12.adicionaForma(5, 5, 'I', 90);
    // game12.adicionaForma(10, 5, 'I', 180);
    // game12.adicionaForma(15, 5, 'I', 270);
    // exibe(game12);

    // cout << game12.adicionaForma(0, 10, 'J', 0) << endl;
    // game12.adicionaForma(5, 10, 'J', 90);
    // game12.adicionaForma(10, 10, 'J', 180);
    // game12.adicionaForma(15, 10, 'J', 270);
    // exibe(game12);

    // game12.adicionaForma(5, 5, 'S', 0);
    // exibe(game12);
    game12.adicionaForma(7, 5, 'L', 270);
    exibe(game12);
    */

    /*Test 10
        Tetris game10(17);
        exibe(game10);

        game10.adicionaForma(0, 0, 'I', 270);
        exibe(game10);

        game10.removeLinhasCompletas();
        game10.removeColuna(16);
        exibe(game10);

        game10.adicionaForma(0, 1, 'I', 90);
        game10.adicionaForma(4, 0, 'I', 90);
        game10.adicionaForma(8, 0, 'I', 90);
        game10.adicionaForma(12, 0, 'I', 90);
        exibe(game10);

        game10.adicionaForma(4, 1, 'I', 90);
        game10.adicionaForma(8, 1, 'I', 90);
        game10.adicionaForma(12, 1, 'I', 90);
        exibe(game10);

        game10.adicionaForma(0, 2, 'I', 90);
        game10.adicionaForma(4, 2, 'I', 90);
        game10.adicionaForma(8, 2, 'I', 90);
        game10.adicionaForma(12, 2, 'I', 90);
        game10.adicionaForma(8, 3, 'I', 90);
        game10.adicionaForma(0, 4, 'I', 90);
        game10.adicionaForma(4, 4, 'I', 90);
        game10.adicionaForma(8, 4, 'I', 90);
        game10.adicionaForma(12, 4, 'I', 90);
        exibe(game10);
        
        game10.adicionaForma(10, 5, 'I', 90);
        game10.adicionaForma(1, 5, 'I', 90);
        exibe(game10);

        game10.removeLinhasCompletas();
        exibe(game10);

        game10.removeColuna(0);
        game10.removeColuna(0);
        game10.removeColuna(0);
        game10.removeColuna(0);
        game10.removeColuna(1);
        game10.removeColuna(1);
        game10.removeColuna(1);
        game10.removeColuna(1);
        game10.removeColuna(1);
        game10.removeColuna(0);
        game10.removeColuna(2);
        game10.removeColuna(3);
        game10.removeColuna(2);
        game10.removeColuna(2);
        exibe(game10);
        
        game10.removeLinhasCompletas();
        exibe(game10);

        game10.adicionaForma(0, 1, 'O', 0);
        exibe(game10);

        game10.removeLinhasCompletas();
        exibe(game10);

        game10.adicionaForma(0, 1, 'O', 0);
        game10.adicionaForma(0, 3, 'O', 0);
        game10.adicionaForma(0, 3, 'O', 0);
        game10.adicionaForma(0, 5, 'O', 0);
        game10.adicionaForma(0, 7, 'O', 0);
        game10.adicionaForma(0, 10, 'O', 0);
        game10.adicionaForma(0, 12, 'O', 0);
        game10.adicionaForma(0, 14, 'O', 0);
        game10.adicionaForma(0, 16, 'O', 0);
        game10.adicionaForma(0, 18, 'O', 0);
        game10.adicionaForma(0, 20, 'O', 0);
        game10.adicionaForma(0, 22, 'O', 0);
        game10.adicionaForma(0, 24, 'O', 0);
        game10.adicionaForma(0, 26, 'O', 0);
        game10.adicionaForma(0, 28, 'O', 0);
        game10.adicionaForma(0, 30, 'O', 0);
        game10.adicionaForma(0, 32, 'O', 0);
        game10.adicionaForma(0, 34, 'O', 0);
        game10.adicionaForma(0, 36, 'O', 0);
        game10.adicionaForma(0, 38, 'O', 0);
        game10.adicionaForma(0, 40, 'O', 0);
        game10.adicionaForma(0, 42, 'O', 0);
        game10.adicionaForma(0, 44, 'O', 0);
        game10.adicionaForma(0, 46, 'O', 0);
        game10.adicionaForma(0, 48, 'O', 0);
        game10.adicionaForma(0, 50, 'O', 0);
        game10.adicionaForma(0, 52, 'O', 0);
        game10.adicionaForma(0, 54, 'O', 0);
        game10.adicionaForma(0, 56, 'O', 0);
        game10.adicionaForma(0, 58, 'O', 0);
        game10.adicionaForma(0, 60, 'O', 0);
        game10.adicionaForma(0, 62, 'O', 0);
        game10.adicionaForma(0, 64, 'O', 0);
        game10.adicionaForma(0, 66, 'O', 0);
        game10.adicionaForma(0, 68, 'O', 0);
        game10.adicionaForma(0, 70, 'O', 0);
        game10.adicionaForma(0, 72, 'O', 0);
        game10.adicionaForma(0, 74, 'O', 0);
        game10.adicionaForma(0, 76, 'O', 0);
        game10.adicionaForma(0, 78, 'O', 0);
        game10.adicionaForma(0, 80, 'O', 0);
        game10.adicionaForma(0, 82, 'O', 0);
        game10.adicionaForma(0, 84, 'O', 0);
        game10.adicionaForma(0, 86, 'O', 0);
        game10.adicionaForma(0, 88, 'O', 0);
        exibe(game10);

        game10.removeLinhasCompletas();
        game10.adicionaForma(1, 5, 'O', 270);
        game10.adicionaForma(0, 5, 'O', 270);
        exibe(game10);
        */

    /*Test 5 */
        // Tetris game5(10)

    return 0;
}