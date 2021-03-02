// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

struct Aluno { 
    // Dados
    std::string _nome;
    std::string _matricula;
    int *_notas;
    int _num_materias;
    int _capacidade;
    int _media_notas;

    // Construtor
    Aluno(std::string nome, std::string matricula);
    // Destrutor
    ~Aluno();

    // funcoes
    void adicionarNota(int nota);
    void calcularMediaAluno();
    void imprimeInformacoesAluno();
};