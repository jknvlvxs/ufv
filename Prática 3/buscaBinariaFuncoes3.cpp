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

int buscaBin(int begin, int end) {
	if (begin > end) return -1;
	int meio = (end-begin)/2 + begin;
	if(consigoAssistirSemPausas(meio) == 0)
		buscaBin(meio+1, end);
	else if(consigoAssistirSemPausas(meio) == 1) {
		if(consigoAssistirSemPausas(meio-1) == 0) return meio; //verifica se o anterior é true
		else return buscaBin(begin, meio-1); 
	}
	return buscaBin(meio+1, end); 	
}

int main() {
	cin >> taxaVideo >> taxaDownload >> tamanho;
	cout << buscaBin(0, 1000000000) << endl;		
}