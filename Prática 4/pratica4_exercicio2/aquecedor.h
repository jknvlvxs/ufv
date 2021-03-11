// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

class Aquecedor {
    private:
        double _temperatura;

    public:
        Aquecedor();

        ~Aquecedor();
        
        double getTemperatura();

        void aumentarTemperatura();

        void abaixarTemperatura();
};