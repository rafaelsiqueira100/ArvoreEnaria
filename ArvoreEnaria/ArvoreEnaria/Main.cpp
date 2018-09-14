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
	const int tamanhoVetor = 55;
	const int vetor[tamanhoVetor] = { 12,39,16,93,65,39,25,24,14,72,
		31,21,27,83,44,29,81,38,63,62,
		67,5,60,86,62,67,5,60,86,62,
		8,63,28,54,8,30,86,34,3,75,
		9,17,83,6,23,30,99,54,74,26,81,80,25,43,24 };
	for (int i = 0; i < tamanhoVetor; i++) {
		MinhaInfo info(vetor[i]);
		MinhaInfo* minhaInfo = new MinhaInfo(info);
		cout << arvore;
		arvore.inserir((InfoArvoreEnaria*)minhaInfo);
		cout << arvore;
	}
	cin >> x;
	return 0;
}