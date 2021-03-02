// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#define TAMANHO_INICIAL 3

struct ListaVetorInteiros { 
    // Dados
    int *_elementos;
    int _num_elementos_inseridos;
    int _capacidade;

    // Construtor
    ListaVetorInteiros();
    // Destrutor
    ~ListaVetorInteiros();

    // Insere um inteiro na lista
    void inserir_elemento(int elemento);
    // Imprime a lista
    void imprimir();  
    
    // Remove o primeiro elemento da lista
    void remover_primeiro();
    // Remove o ultimo elemento da lista
    void remover_ultimo();
    // Inverte os valores da lista
    void inverte();
};