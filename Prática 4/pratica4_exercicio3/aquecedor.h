// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

class Aquecedor {
    private:
        double _temperatura;
        double _temperatura_minima;
        double _temperatura_maxima;
        double _fator_incremento;

    public:
        Aquecedor();

        Aquecedor(double temperatura);

        Aquecedor(double temperatura, double fator_incremento);

        ~Aquecedor();
        
        double getTemperatura();

        void aumentarTemperatura();

        void abaixarTemperatura();

        void setFatorIncremento(double fator_incremento);
};