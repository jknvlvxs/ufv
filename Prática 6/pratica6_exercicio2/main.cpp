// Universidade Federal de Viçosa - Ciência da Computação
// Disciplina: INF112 - Programação II
// Autor: José Júlio Alves Campolina
// Número de Matrícula: 102022 

#include <iostream>
#include <iomanip>

#include "produto.h"
#include "medicamento.h"
#include "higiene.h"

using namespace std;

void exibir_produto(Produto &produto){
    cout << "Código: " << produto.get_codigo();
    cout << " | Descrição: " << produto.get_descricao();
    cout << " | Preço de Compra: " << produto.get_preco_compra();
    cout << " | Percentual de Lucro: " << produto.get_percentual_lucro() << "%";
    cout << " | Preço de Venda: " << produto.gerarPrecoDeVenda() << endl;
}

int main() {
    cout << setprecision(2) << fixed;

    Produto *r1 = new Medicamento("123", "Rivotril", 120, 6, 10);
    Produto *r2 = new Medicamento("321", "Xanax", 100, 12, 5);
    Produto *h1 = new Higiene("321", "Shampoo", 50);
    Produto *h2 = new Higiene("321", "Pasta de Dente", 120);

    exibir_produto(*r1);
    exibir_produto(*r2);
    exibir_produto(*h1);
    exibir_produto(*h2);

    delete r1;
    delete r2;
    delete h1;
    delete h2;

    return 0;
}