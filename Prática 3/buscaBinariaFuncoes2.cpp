#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

//Vamos usar variaveis globais nesse caso...
//Isso nao é uma boa pratica, mas vai facilitar no seu entendimento/implementacao da busca binaria
int taxaVideo,taxaDownload,tamanho;

//Essa funcao devera retornar true sse for possível 
//assistir a um vídeo de "tamanho" segundos, que gasta taxaVideo bytes por segundo para ser assistido
//supondo que sua internet consegue baixar taxaDownload bytes por segundo.
//tempoCarregamento indica quanto tempo voce irá aguardar para começar assistir ao vídeo
//Implemente esta funcao
bool consigoAssistirSemPausas(int tempoCarregamento) {
	long long int bytesBaixados = (long long)(tempoCarregamento) * taxaDownload;

	for(int i = 0; i < tamanho; i++){
		bytesBaixados = bytesBaixados - taxaVideo + taxaDownload;
		if(bytesBaixados < 0) return false;
	}

	return true;
}

int buscaSeq(int begin, int end) {
	for(int i=begin;i<=end;i++)
		if (consigoAssistirSemPausas(i))
			return i;		
	return 0;
}

int main() {
	cin >> taxaVideo >> taxaDownload >> tamanho;
	cout << buscaSeq(0, 1000000000) << endl;		
}