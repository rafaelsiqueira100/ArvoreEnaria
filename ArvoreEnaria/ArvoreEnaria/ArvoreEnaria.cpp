
#include "ArvoreEnaria.h"


ArvoreEnaria::ArvoreEnaria(unsigned int numInfo)
{
	this->numInfo = numInfo;
	this->raiz = nullptr;
}


ArvoreEnaria::~ArvoreEnaria()
{
	if (this->raiz != nullptr)
		delete[] raiz;
}


ostream& operator<< (ostream& os, const ArvoreEnaria& arvore) {
	if (arvore.raiz == nullptr)
		return os<<"{  }"<<'\n';
	return	os <<'{' <<*(arvore.raiz)<<'}'<<'\n';
	
}
char ArvoreEnaria::inserir(InfoArvoreEnaria* info) throw(char*){
	char achouLugar = 0;
	NoArvoreEnaria* noAtual(raiz);
	if (this->raiz == nullptr)
		raiz = new NoArvoreEnaria(this->numInfo);
	if ((this->raiz->isVazio())) {
		this->raiz == nullptr;
		raiz = new NoArvoreEnaria(this->numInfo);
	}
loop:while (1) {
		if (noAtual == nullptr ) {
			//noAtual é = raiz
			raiz = new NoArvoreEnaria(this->numInfo);
			noAtual = raiz;

		}
		if ((*(noAtual)).isCheio()) {
			int i;
			for (i = 0; i < this-> numInfo; i++) {
				//if ((noAtual)->getPtrInfo(i) != nullptr)  nó está cheio
				if (*((noAtual)->getPtrInfo(i)) == *info) {
					//throw("Informação já está na árvore!");
					return -1;
				}
				if (*((noAtual)->getPtrInfo(i)) > *info) {
						
						//deve-se inserir a partir do nó que é apontado pelo ponteiro que está entre i e i-1(ponteiro i)
						if ((noAtual)->getPtrNoFilho(i) != nullptr) {
							noAtual = (noAtual->getPtrNoFilho(i));
							//volta pra iteração
							goto loop;
						}
						else {
							//criar esse nó
							//NoArvoreEnaria* filho = new NoArvoreEnaria(this->numInfo);
							//(*filho).colocarVetorOrdem(info);
							NoArvoreEnaria* auxiliar = new NoArvoreEnaria(this->numInfo);
							(*auxiliar).colocarVetorOrdem(info);
							noAtual->setPtrNoFilho(auxiliar, i);
							return 1;
						}
					}
				
			}//fim do for
			//aqui i=numInfos
			if (*(noAtual)->getPtrInfo(i-1) < *info) {
				//ir para o nó à direita
				if ((noAtual)->getPtrNoFilho(i) != nullptr) {
					noAtual = (noAtual->getPtrNoFilho(i));
					//volta pra iteração
				}
				else {
					//criar esse nó
					NoArvoreEnaria* filho = (new NoArvoreEnaria(this->numInfo));
					//InfoArvoreEnaria* novaInfo = info;

					(*filho).colocarVetorOrdem(info);
					noAtual->setPtrNoFilho(filho, i);
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
	bool raizEhVazia = this->raiz->isVazio();
	if (raizEhVazia) {
		this->raiz = nullptr;
	}
	/*if (this->raiz->isVazio()) {
		this->raiz = nullptr;
	}*/
}

NoArvoreEnaria* ArvoreEnaria::getRaiz() const throw(char*) {
	return this->raiz;
}