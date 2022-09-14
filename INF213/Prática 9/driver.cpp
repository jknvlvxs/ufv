#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"
#include "MyStack.h"
#include "MyQueue.h"

void etapa1() {
	int leitura;
	MyQueue<int> fila;
	MyStack<int> pilha;

	for(int i = 0; i<6; i++){
		cin >> leitura;
		fila.push(leitura);
		pilha.push(leitura);
	}

	/* A consulta da pilha se dá a partir do topo, onde os numeros inseridos vão empilhando no topo
	logo, sua exibição é invertida */
	for(int i = 0; i<6; i++){
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << endl;

	/* A consulta da fila se dá a partir do inicio, porém os numeros inseridos vão para o final da fila
	logo, sua exibição é normal */
	for(int i = 0; i<6; i++){
		cout << fila.front() << " ";
		fila.pop();
	}

	cout << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....
bool verificaCaracteres(MyStack<int> &pilha, char c){
	while(cin >> c){
		if(c == '(' || c == '[' || c == '{')
			pilha.push(c);

		if(pilha.empty())
			return false;

		switch (c) {
		case ')':
			if(pilha.top() != '(') return false;
			pilha.pop();
			break;
		case ']':
			if(pilha.top() != '[') return false;
			pilha.pop();
			break;
		case '}':
			if(pilha.top() != '{') return false;
			pilha.pop();
			break;
		}
	}
	return pilha.empty();
}

void etapa2() {
	MyStack<int> pilha;
	char crc;

	cout << (verificaCaracteres(pilha, crc) ? "Consistente" : "Inconsistente") << endl;
}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


// #include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> elem;
		mediana.insere(elem);
		// mediana.imprime();
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}