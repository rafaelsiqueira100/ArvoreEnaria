#include <iostream>
#include <cstdlib>
#include "ArvoreEnaria.h"
#include "MinhaInfo.h"
using namespace std;
int main()
{
	char x;
	unsigned int n;
	cout << "Digite o número de informações n de cada nó da árvore. O número de ponteiros vale n+1. ...";
	cin >> n;
	if (n == 0)
		cout << "Número não pode ser 0";
	ArvoreEnaria arvore(n);
	const int tamanhoVetor = 15;
	const int vetor[tamanhoVetor] = { 12,39,16,93,65,25,24,14,72,
		31,21,27,83,44,97 };
	MinhaInfo* minhaInfo;
	for (int i = 0; i < tamanhoVetor; i++) {
		
		minhaInfo = new MinhaInfo(vetor[i]);
		//cout << arvore;
		arvore.inserir((InfoArvoreEnaria*)minhaInfo);
		cout << arvore;
	}
	const int vetInd[tamanhoVetor] = { 4,1,8,6,14,7,9,2,12,11,5,13,0,10,3 };
	MinhaInfo* infoRemover;
	for (int j = 0; j < tamanhoVetor; j++) {
		
		infoRemover = new MinhaInfo(vetor[vetInd[j]]);
		cout << '\n';
		arvore.remover((InfoArvoreEnaria*)infoRemover);
		cout << arvore;

		cout << '\n';
	}
	cin >> x;
	delete infoRemover;
	delete minhaInfo;
	return 0;
}