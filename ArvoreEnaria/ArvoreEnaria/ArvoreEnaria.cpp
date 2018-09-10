#include "stdafx.h"
#include "ArvoreEnaria.h"


ArvoreEnaria::ArvoreEnaria(unsigned int numInfo)
{
}


ArvoreEnaria::~ArvoreEnaria()
{
}


ostream& operator<< (ostream& os, const ArvoreEnaria& arvore) {
	return	os << arvore.raiz;
	
}
void ArvoreEnaria::inserir(InfoArvoreEnaria* info) throw(char*){
	char achouLugar = 0;
	NoArvoreEnaria* noAtual(raiz);
	while (1) {
		if ((*(noAtual)).isCheio()) {
			int i;
			for (i = 0; i < this-> numInfo; i++) {
				//if ((noAtual)->getPtrInfo(i) != nullptr)  nó está cheio
				if (*(noAtual)->getPtrInfo(i) == *info) {
					throw("Informação já está na árvore!");
				}
				if (*(noAtual)->getPtrInfo(i) > *info) {
						//deve-se inserir a partir do nó que é apontado pelo ponteiro que está entre i e i-1(ponteiro i-1)
						if ((noAtual)->getPtrNoFilho(i) != nullptr) {
							noAtual = (noAtual->getPtrNoFilho(i));
							//volta pra iteração
						}
						else {
							//criar esse nó
							NoArvoreEnaria* filho = noAtual->getPtrNoFilho(i);
							filho = new NoArvoreEnaria(this->numInfo);
							(*filho).colocarVetorOrdem(info);
							return;
						}
					}
				
			}//fim do for
			if (*(noAtual)->getPtrInfo(i) < *info) {
				if ((noAtual)->getPtrNoFilho(i) != nullptr) {
					noAtual = (noAtual->getPtrNoFilho(i));
					//volta pra iteração
				}
				else {
					//criar esse nó
					NoArvoreEnaria* filho = noAtual->getPtrNoFilho(i);
					filho = new NoArvoreEnaria(this->numInfo);
					(*filho).colocarVetorOrdem(info);
					return;
				}
			}
		}
		else {
			noAtual->colocarVetorOrdem(info);
			return;
		}
	}
}