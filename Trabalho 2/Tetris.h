#ifndef TETRIS_H
#define TETRIS_H

class Tetris {
    protected:
        char** jogo;
        int largura;
        int* alturas;

        void create(int c);
        void clear();
    private:
        void preencheColuna(int c, int l);
        bool verificaPeca(int c, int l);
        void corrigeAltura(int c);
    public:
        Tetris(int c);
        Tetris(const Tetris &outro);
        Tetris & operator=(const Tetris &);
        ~Tetris();
        
        char get(int c, int l) const;
        void removeColuna(int c);
        void removeLinhasCompletas();
        int getNumColunas() const;
        int getAltura(int c) const;
        int getAltura() const;
        bool adicionaForma(int c, int l, char id, int rotacao);

};

#endif