// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

struct Data { 
    // Dados
    int _dia;
    int _mes;
    int _ano;

    // Construtor
    Data(int dia, int mes, int ano);
    // Destrutor
    ~Data();

    // funcoes
    void getDataBarra();
    void getDataExtenso();
    void getDataEmSegundos();
};