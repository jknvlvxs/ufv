// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

class Rectangle {
    private:
        double _width;
        double _length;

    public:
        Rectangle();

        ~Rectangle();
        
        double getWidth();

        double getLength();

        void setWidth(double width);

        void setLength(double length);

        double getPerimeter();

        double getArea();
};