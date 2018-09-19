
#include "ArvoreEnaria.h"


ArvoreEnaria::ArvoreEnaria(unsigned int numInfo)
{
	this->numInfo = numInfo;
	this->raiz = nullptr;
}


ArvoreEnaria::~ArvoreEnaria()
{
}


ostream& operator<< (ostream& os, const ArvoreEnaria& arvore) {
	if (arvore.raiz == nullptr)
		return os<<"{  }"<<'\n';
	return	os <<'{' <<*(arvore.raiz)<<'}'<<'\n';
	
}
char ArvoreEnaria::inserir(InfoArvoreEnaria* info) throw(char*){
	char achouLugar = 0;
	NoArvoreEnaria* noAtual(raiz);
	while (1) {
		if (noAtual == nullptr ) {
			//noAtual é = raiz
			raiz = new NoArvoreEnaria(this->numInfo);
			noAtual = raiz;

		}
		if ((*(noAtual)).isCheio()) {
			int i;
			for (i = 0; i < this-> numInfo; i++) {
				//if ((noAtual)->getPtrInfo(i) != nullptr)  nó está cheio
				if (*(noAtual)->getPtrInfo(i) == *info) {
					throw("Informação já está na árvore!");
				}
				if (*(noAtual)->getPtrInfo(i) > *info) {
						
						//deve-se inserir a partir do nó que é apontado pelo ponteiro que está entre i e i-1(ponteiro i)
						if ((noAtual)->getPtrNoFilho(i) != nullptr) {
							noAtual = (noAtual->getPtrNoFilho(i));
							//volta pra iteração
						}
						else {
							//criar esse nó
							NoArvoreEnaria* filho = new NoArvoreEnaria(this->numInfo);
							(*filho).colocarVetorOrdem(info);
							noAtual->setPtrNoFilho(filho, i);
							return 1;
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
					InfoArvoreEnaria* novaInfo = info;

					(*filho).colocarVetorOrdem(info);
					noAtual = (noAtual)->getPtrNoFilho(i);
					noAtual = filho;
					return 1;
				}
			}
		}
		else {
			noAtual->colocarVetorOrdem(info);
			return 1;
		}
	}
	return 0;
}

char ArvoreEnaria::remover(InfoArvoreEnaria* info) throw(char*) {
	
	if (this->raiz == nullptr) {
		//árvore está vazia
		throw("Tentativa de remoção em árvore vazia!");
	}
	this->raiz->removerVetorOrdem(info);
	if (this->raiz->isVazio())
		this->raiz == nullptr;
}

NoArvoreEnaria* ArvoreEnaria::getRaiz() const throw(char*) {
	return this->raiz;
}