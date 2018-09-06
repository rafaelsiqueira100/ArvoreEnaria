#include "stdafx.h"
#include "NoArvoreEnaria.h"


NoArvoreEnaria::NoArvoreEnaria(unsigned int numInfos)
{
	if (numInfos == 0)
		throw("Número de Informações inválido!");

	this->numInfos = numInfos;
	this->vetPtrInfo = new InfoArvoreEnaria*[numInfos];
	this->vetPtrNo = new NoArvoreEnaria*[numInfos + 1];

}
NoArvoreEnaria::NoArvoreEnaria(NoArvoreEnaria noBase)throw(char*)
{
	if(noBase.getNumInfos==0)
		throw("Número de Informações do Objeto Base inválido!");
	this->numInfos = noBase.numInfos;
	this->vetPtrInfo = new InfoArvoreEnaria*[numInfos];
	this->vetPtrNo = new NoArvoreEnaria*[numInfos+1];
	for (int i = 0; i < numInfos; i++) {

	}
}

NoArvoreEnaria::~NoArvoreEnaria()
{
}
ostream& operator<< (ostream& os, const NoArvoreEnaria& no) throw() {
	int indicePtr = 0;
	int indiceInfo = 0;

	for (indicePtr = 0; indicePtr < no.getNumInfos() + 1; indicePtr++) {


		if (no.getPtrNoFilho(indicePtr) != nullptr) {
			os << no.getPtrNoFilho(indicePtr);
		}
		os << no.getPtrInfo(indicePtr);
	}

}
NoArvoreEnaria* NoArvoreEnaria::getPtrNoFilho(unsigned int indFilho) const throw() {

	return *(vetPtrNo + indFilho);
}
InfoArvoreEnaria* NoArvoreEnaria::getPtrInfo(unsigned int indInfo) const throw() {
	return *(vetPtrInfo + indInfo);
}
char NoArvoreEnaria::colocarVetorOrdem(InfoArvoreEnaria* info) const throw() {
	if (info == nullptr)
		return -1;
	//supondo vetor está ordenado;
	for (int i = 0; i < this->numInfos; i++) {
		if (*(vetPtrInfo + i) != nullptr) {
			if (**(vetPtrInfo + i) > *info) {
				//tem que inserir no lugar de i
				for (int j = numInfos - 1; j >= i; j--) {
					*(this->vetPtrInfo + j + 1) = *(this->vetPtrInfo + j);
				}
				*(this->vetPtrInfo + i) = info;
			}
		}
		else {
			*(vetPtrInfo + i) = info;
		}
	}
}
char NoArvoreEnaria::isCheio() const throw() {
	for (int i = 0; i < numInfos; i++)
		if (*(vetPtrInfo + i) == nullptr)
			return 0;
	return 1;
}
char NoArvoreEnaria::haInfo(InfoArvoreEnaria* info)const throw() {
	NoArvoreEnaria noRel(this);
	while (1) {
		for (int i = 0; i < numInfos; i++) {
			if ((*vetPtrInfo + i) != nullptr) {
				if ((*vetPtrInfo + i) == info) {
					return true;
				}
				if ((*vetPtrInfo + i) > info) {
					//ir pro ponteiro de nó i-1


				}
			}
			else {
				return false;
			}
		}
	}
}