#include <iostream>

using namespace std;

int main () {
    long value1 = 200000, value2;

    // (a) Declare a variável longPtr como um ponteiro para um objeto do tipo long
    long *longPtr;

    // (b) Atribua o endereço da variável value1 à variável ponteiro longPtr.
    longPtr = &value1;

    // (c) Imprima o valor do objeto apontado por longPtr.
    cout << *longPtr << endl;

    // (d) Atribua o valor do objeto apontado por longPtr à variável value2.
    value2 = *longPtr;

    // (e) Imprima o valor de value2.
    cout << value2 << endl;

    // (f) Imprima o endereço de value1.
    cout << &value1 << endl;

    // (g) Imprima o endereço armazenado em longPtr.
    cout << longPtr << endl;

    // O valor impresso é o mesmo que o endereço de value1? Escreva sua observação como um comentário no seu código submetido.
    // Sim, o valor impresso do endereço armazenado em longPtr é o mesmo que o endereço de value1, pois esse valor do endereço é atribuído a longPtr ao receber &value1
    
    return 0;
}