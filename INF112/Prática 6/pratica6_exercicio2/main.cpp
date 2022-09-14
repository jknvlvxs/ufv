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

    Produto *r1 = new Medicamento("12811", "Cimegripe 400mg 20 Cápsulas", 20.51, 7, 5);
    Produto *r2 = new Medicamento("16377", "Loratamed 10mg 12 Comprimidos", 17.09, 9, 3);
    Produto *h1 = new Higiene("63088", "Sabonete Dove Leve 6 Pague 5 90g", 12.64);
    Produto *h2 = new Higiene("135895", "Creme Dental Colgate Sensitive Pró-Alivio Original 140g", 8.99);

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