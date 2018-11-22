#include "MinhaInfo.h"
#include "NoArvoreEnaria.h"
using namespace std;

NoArvoreEnaria::NoArvoreEnaria(unsigned int numInfos)
{
	if (numInfos == 0)
		throw("Número de Informações inválido!");

	this->numInfos = numInfos;
	this->vetPtrInfo = new InfoArvoreEnaria*[numInfos];
	this->vetPtrNo = new NoArvoreEnaria*[numInfos + 1];
	for (int i = 0; i < numInfos; i++) {
		*(this->vetPtrInfo + i) = nullptr;
		*(this->vetPtrNo + i) = nullptr;
	}
	*(this->vetPtrNo + numInfos) = nullptr;
	this->reestruturando = 0;

}
NoArvoreEnaria::NoArvoreEnaria(const NoArvoreEnaria& noBase)throw(char*)
{
	if(noBase.getNumInfos()==0)
		throw("Número de Informações do Objeto Base inválido!");
	this->numInfos = noBase.numInfos;
	this->vetPtrInfo = new InfoArvoreEnaria*[numInfos];
	
	this->vetPtrNo = new NoArvoreEnaria*[numInfos+1];
	int i;
	for (i = 0; i < numInfos; i++) {
		//this->vetPtrInfo[0] = new NoArvoreEnaria()
		if (noBase.getPtrInfo(i) != nullptr)
			*(this->vetPtrInfo + i) = (noBase.getPtrInfo(i));//se alterar um futuramente, altera o outro
		else
			*(this->vetPtrInfo + i) = nullptr;
			//**(this->vetPtrInfo + i) = *(noBase.getPtrInfo(i));

		if (noBase.getPtrNoFilho(i) != nullptr)
			*(this->vetPtrNo + i) = new NoArvoreEnaria(*(noBase.getPtrNoFilho(i)));
		else
			*(this->vetPtrNo + i) = nullptr;

	}
	if (noBase.getPtrNoFilho(i) != nullptr)
		*(this->vetPtrNo + numInfos) = new NoArvoreEnaria(*(noBase.getPtrNoFilho(i)));
	else
		*(this->vetPtrNo + numInfos) = nullptr;
}

NoArvoreEnaria::~NoArvoreEnaria()
{
	if (this->vetPtrInfo != nullptr) {
		for (int i = 0; i < this->numInfos; i++) {
			if (*(this->vetPtrInfo + i) != nullptr) {
				delete[](*(this->vetPtrInfo + i));
			}
		}
		delete[] this->vetPtrInfo;
	}
	if (this->vetPtrNo != nullptr) {
		for (int i = 0; i <= this->numInfos; i++) {
			if (*(this->vetPtrNo + i) != nullptr) {
				delete[](*(this->vetPtrNo + i));
			}
		}
		delete[] this->vetPtrNo;
	}

}
int NoArvoreEnaria::getNumInfos()const throw() {
	try {
		if (this != nullptr)
			return this->numInfos;
		else
			return -1;
	}
	catch (exception& a) {
		return -2;
	}
}
ostream& operator<< (ostream& os, const NoArvoreEnaria& no) throw() {
	int indicePtr = 0;
	int indiceInfo = 0;
	int numInfos = 0;
	try {
		numInfos = no.getNumInfos();
	}
	catch (exception& a) {
		os << " ** ";
		return os;
	}

	if (numInfos < 1) {
		os << " ** ";
		return os;
	}
	//os << '[';
	for (indicePtr = 0; indicePtr < numInfos ; indicePtr++) {


		if (no.getPtrNoFilho(indicePtr) != nullptr){// && no.getPtrNoFilho(indicePtr) != (NoArvoreEnaria*)0xFFFFFFFFFFFFFFEF) {
			os <<" [ " << *(no.getPtrNoFilho(indicePtr))<<" ] ";
		}
		else { 
			os << " (  ||  ) ";
		}
		if (no.getPtrInfo(indicePtr) != nullptr) {
			InfoArvoreEnaria* info = (no.getPtrInfo(indicePtr));
			os << "  " <<(*(info)) << "  ";
		}
		else {
			os << "  **  ";
		}
	}
	if (no.getPtrNoFilho(numInfos) != nullptr) {
		os << " [ " << *(no.getPtrNoFilho(numInfos)) << " ] ";
	}
	else {
		os << " (  ||  ) ";
	}
	return os;
}
NoArvoreEnaria* NoArvoreEnaria::getPtrNoFilho(unsigned int indFilho) const throw() {

	return *(vetPtrNo + indFilho);
}

void NoArvoreEnaria::setPtrNoFilho(NoArvoreEnaria* novoNo,unsigned int indFilho) const throw() {
	if (novoNo == nullptr) {
		*(vetPtrNo + indFilho) = new NoArvoreEnaria(*novoNo);
		return;
	}
	if (*(this->vetPtrNo + indFilho) == nullptr)
		*(vetPtrNo + indFilho) = new NoArvoreEnaria(*novoNo);
	else
		**(vetPtrNo + indFilho) = *novoNo;
}
InfoArvoreEnaria* NoArvoreEnaria::getPtrInfo(unsigned int indInfo) const throw() {
	return *(vetPtrInfo + indInfo);
}
char NoArvoreEnaria::colocarVetorOrdem(InfoArvoreEnaria* info) throw() {
	if (info == nullptr)
		return -1;
	//supondo vetor está ordenado;
	for (int i = 0; i < this->numInfos; i++) {
		if (*(vetPtrInfo + i) != nullptr) {
			if (**(vetPtrInfo + i) > *info) {
				//tem que inserir no lugar de i
				for (int j = numInfos - 1; j > i; j--) {
					if (*(this->vetPtrInfo + j - 1) != nullptr)
						*(this->vetPtrInfo + j) = (new MinhaInfo(**(this->vetPtrInfo + j - 1)));
					else
						*(this->vetPtrInfo + j) = nullptr;
				}
				*(this->vetPtrInfo + i) = new MinhaInfo(*info);
				return 1;
			}
		}
		else {
			*(vetPtrInfo + i) = /*new MinhaInfo(**/info/*)*/;

			return 1;
		}
	}
}
char NoArvoreEnaria::removerVetorOrdem(InfoArvoreEnaria* info) throw() {
	if (info == nullptr)
		return -1;
	if (!haInfo(info))
		return -1;
	//ordenar vetor
	int indiceInfo = -1;
	//supondo vetor está ordenado
	for (int i = 0; i < this->numInfos; i++) {
		if (*(vetPtrInfo + i) != nullptr) {
			if (**(vetPtrInfo + i) == *info) {
				indiceInfo = i;
			}
		}
	}
	if (indiceInfo == -1) { //não achou essa info nesse nó
	//ela está num nó filho
		for (int i = 0; i < numInfos; i++) {
			if (**(this->vetPtrInfo + i) > *info) {
				//ir pro ponteiro de nó i-1 (esquerda)
				char resultado = (*(vetPtrNo + i))->removerVetorOrdem(info);
				if ((*(vetPtrNo + i))->isVazio())
					(*(vetPtrNo + i)) = nullptr;
				return resultado;
				//goto loop;
			}
			if (**(this->vetPtrInfo + i) < *info) {
				//ir pra direita
				char resultado = (*(vetPtrNo + i + 1))->removerVetorOrdem(info);
				if ((*(vetPtrNo + i + 1))->isVazio())
					(*(vetPtrNo + i + 1)) = nullptr;
				return resultado;
				//goto loop;
			}
		}
	}
		
	if (this->isFolha()) {//se é folha
		*(this->vetPtrInfo + indiceInfo) = nullptr;
		if (indiceInfo == 0) {//remover a informação 0, o vetor vai ficar vazio
			
		}
		for (int i = indiceInfo + 1; i < this->numInfos; i++) {
			*(this->vetPtrInfo + i - 1) = *(this->vetPtrInfo + i);

		}//reestruturando o nó
		
		
		return 1;
	}
	else {//se não é folha
		
			InfoArvoreEnaria& infoRemovida = **(this->vetPtrInfo + indiceInfo);
			//*(this->vetPtrInfo + indiceInfo) = nullptr;

			InfoArvoreEnaria* infoSubstit = &(this->acharInfoPorLugar(infoRemovida, indiceInfo));

			int indiceInserir;
			for (indiceInserir = 0; indiceInserir < this->numInfos; indiceInserir++) {
				if (*(vetPtrInfo + indiceInserir) == nullptr) {
					//ESTÁ NA INFO REMOVIDA
					if (infoRemovida > *infoSubstit) {
						goto saiLoop;
					}
				}
				if ((*(*(vetPtrInfo + indiceInserir))) > *infoSubstit) {
					goto saiLoop;
				}

			}

		saiLoop:
			if ((*(vetPtrInfo + numInfos - 1)) == nullptr) {
				//ESTÁ NA INFO REMOVIDA
				if (infoRemovida < *infoSubstit) {
					//informação Substituta é a maior do vetor
					indiceInserir = this->numInfos - 1;
				}
			}
			else {
				if ((*(*(vetPtrInfo + numInfos - 1))) < *infoSubstit) {
					//informação Substituta é a maior do vetor
					indiceInserir = this->numInfos - 1;
				}
			}
			if (indiceInserir < indiceInfo) {
				//deslocamento para direita
				for (int i = indiceInfo; i > indiceInserir; i--) {
					*(vetPtrInfo + i) = *(vetPtrInfo + i - 1);
					*(vetPtrNo + i + 1) = *(vetPtrNo + i);

				}
				*(vetPtrNo + indiceInserir + 1) = *(vetPtrNo + indiceInserir);
				*(vetPtrInfo + indiceInserir) = infoSubstit;
			}
			if (indiceInserir == indiceInfo) {
				*(this->vetPtrInfo + indiceInfo) = infoSubstit;
			}
			if (indiceInserir > indiceInfo) {
				//deslocamento para esquerda
				for (int i = indiceInfo; i < indiceInfo; i++) {
					*(vetPtrInfo + i) = *(vetPtrInfo + i + 1);

					*(vetPtrNo + i) = *(vetPtrNo + i + 1);
				}
				*(vetPtrNo + indiceInserir) = *(vetPtrNo + indiceInserir + 1);
				*(vetPtrInfo + indiceInserir) = infoSubstit;

			}
			this->conferirNosVazios();
			return 1;
		
		
	}

}
char NoArvoreEnaria::isFolha() const throw() {
	if (!this->isCheio())
		return 1;
	char naoHaFilho = 1;
	for (int i = 0; i < numInfos + 1; i++)
		if (*(vetPtrNo + i) != nullptr)
			naoHaFilho = 0;
	return naoHaFilho;
}
char NoArvoreEnaria::isCheio() const throw() {
	
	for (int i = 0; i < numInfos; i++)
		if (*(vetPtrInfo + i) == nullptr)
			return 0;
	return 1;
}
char NoArvoreEnaria::isVazio() const throw() {
	
	for (int i = 0; i < numInfos; i++)
		if (*(vetPtrInfo + i) != nullptr)
			return 0;
	return 1;
}
char NoArvoreEnaria::haInfo(InfoArvoreEnaria* info)const throw() {
	NoArvoreEnaria* noRel = (NoArvoreEnaria*)(this);
	while (1) {
	loop:for (int i = 0; i < numInfos; i++) {
		if (noRel == nullptr) {
			return false;
		}
		if (*(noRel->vetPtrInfo + i) != nullptr) {
			if (**(noRel->vetPtrInfo + i) == *info) {
				return true;
			}
			if (**(noRel->vetPtrInfo + i) > *info) {
				//ir pro ponteiro de nó i-1 (esquerda)
				noRel = *(noRel->vetPtrNo + i);
				goto loop;
			}
			if (**(noRel->vetPtrInfo + i) < *info) {
				//ir pra direita
				noRel = *(noRel->vetPtrNo + i + 1);
				goto loop;
			}

		}
		else {
			return false;
		}
	}
	}
}
InfoArvoreEnaria& NoArvoreEnaria::acharInfoPorLugar(InfoArvoreEnaria& infoATrocar, unsigned int indiceInfoTrocar) {
	
	NoArvoreEnaria* noRel = (NoArvoreEnaria*)this;
	//NoArvoreEnaria* noPaiRel = nullptr;//noPaiRel só existe se ehFolha
	char ehFolha = 0;
	char sentido = 0;
	int i = 0;
loop:for (; i < noRel->numInfos; i++) {
maiorEsq:if (sentido > -1 /*&& *(noRel->vetPtrNo + indiceInfoTrocar - i) != nullptr*/) {
			//achar o maior valor dessa subárvore esquerda
			int indiceInfoFilho = -1;
			if ((*(noRel->vetPtrNo + indiceInfoTrocar - i)) == nullptr) {
				/*if (!ehFolha) {
					i++;
					goto loop;
				}
				else {
					while (indiceInfoFilho < numInfos - 1 && (noRel->getPtrInfo(indiceInfoFilho + 1) != nullptr))
						indiceInfoFilho++;
				}*/
				goto menorDir;
			}
			else {
				while (indiceInfoFilho < numInfos - 1 && (*(noRel->vetPtrNo + indiceInfoTrocar - i))->getPtrInfo(indiceInfoFilho + 1) != nullptr)
					indiceInfoFilho++;

			}//indiceInfoFilho representa o índice do maior info do filho encontrado
			if (!ehFolha &&(*(noRel->vetPtrNo + indiceInfoTrocar - i))->getPtrNoFilho(indiceInfoFilho+1) != nullptr) {
				//esse info tem outros infos depois dele
				sentido = 1;
				//noPaiRel = (*(noRel->vetPtrNo + indiceInfoTrocar - i));
				noRel = (*(noRel->vetPtrNo + indiceInfoTrocar - i))->getPtrNoFilho(indiceInfoFilho+1);
				ehFolha = noRel->isFolha();
				
			
				indiceInfoTrocar = indiceInfoFilho +1;
				goto loop;
			}
			else {
				//esse info é o desejado para trocar
			//é o maior valor da subárvore esquerda de noRel
			//remover primeiro, depois retornar
				if(!ehFolha){
				InfoArvoreEnaria& infoTrocarFilho =
					*(new MinhaInfo(*((*(noRel->vetPtrNo + indiceInfoTrocar - i))->getPtrInfo(indiceInfoFilho))));
				(*(noRel->vetPtrNo + indiceInfoTrocar - i))->removerVetorOrdem(&infoTrocarFilho);
				if ((*(noRel->vetPtrNo + indiceInfoTrocar - i))->isVazio())
					*(noRel->vetPtrNo + indiceInfoTrocar - i) = nullptr;
				return *(new MinhaInfo(infoTrocarFilho));
				}
				else {
					InfoArvoreEnaria& infoTrocarFilho =
						*(new MinhaInfo(*(noRel->getPtrInfo(indiceInfoFilho))));
					((noRel))->removerVetorOrdem(&infoTrocarFilho);
					if (((noRel))->isVazio())
						(noRel) = nullptr;
					/*if (noPaiRel->isVazio())
						noPaiRel = nullptr;*/
					return *(new MinhaInfo(infoTrocarFilho));
				}
			}
		}
menorDir:if (sentido < 1 /*&& *(noRel->vetPtrNo + indiceInfoTrocar + i+1) != nullptr*/) {
			//achar o menor valor dessa subárvore direita
			int indiceInfoFilho = numInfos;
			if ((*(noRel->vetPtrNo + indiceInfoTrocar + i + 1)) != nullptr)
				while (indiceInfoFilho > 0 && (*(noRel->vetPtrNo + indiceInfoTrocar + i + 1))->getPtrInfo(indiceInfoFilho) != nullptr)
					indiceInfoFilho--;
			else {
				if (!ehFolha) {
					i--;
					goto loop;
				}
				else {
					while (indiceInfoFilho > 0 && (noRel)->getPtrInfo(indiceInfoFilho) != nullptr)
						indiceInfoFilho--;
				}
			}
				//indiceInfoFilho representa o índice do menor info do filho encontrado
			if (!ehFolha &&(*(noRel->vetPtrNo + indiceInfoTrocar + i+1))->getPtrNoFilho(indiceInfoFilho) != nullptr) {
				//esse info tem outros infos antes dele
				sentido = -1;
				//noPaiRel = (*(noRel->vetPtrNo + indiceInfoTrocar + i + 1));
				noRel = (*(noRel->vetPtrNo + indiceInfoTrocar + i+1))->getPtrNoFilho(indiceInfoFilho);
				ehFolha = noRel->isFolha();
					
				
				i = 0;
				goto loop;
			}
			else {
				//esse info é o desejado para trocar
				//é o menor valor da subárvore direita de noRel
			//remover primeiro, depois retornar
				if (!ehFolha) {
					InfoArvoreEnaria& infoTrocarFilho =
						*(new MinhaInfo(*((*(noRel->vetPtrNo + indiceInfoTrocar + i + 1))->getPtrInfo(indiceInfoFilho))));
					(*(noRel->vetPtrNo + indiceInfoTrocar + i + 1))->removerVetorOrdem(&infoTrocarFilho);
					if ((*(noRel->vetPtrNo + indiceInfoTrocar + i + 1))->isVazio())
						*(noRel->vetPtrNo + indiceInfoTrocar + i + 1) = nullptr;

					return *(new MinhaInfo(infoTrocarFilho));
				}
				else {
					InfoArvoreEnaria& infoTrocarFilho =
						*(new MinhaInfo(*(noRel->getPtrInfo(indiceInfoFilho))));
					((noRel))->removerVetorOrdem(&infoTrocarFilho);
					if (((noRel))->isVazio())
						(noRel) = nullptr;

					/*if (noPaiRel->isVazio())
						noPaiRel = nullptr;*/
					return *(new MinhaInfo(infoTrocarFilho));
				}
			}
		}
	}
}

void NoArvoreEnaria::conferirNosVazios()
{
	if (this->isFolha())
		return;
	bool haFilhoFolha = false;
	for (int i = 0; i < numInfos + 1; i++) {
		NoArvoreEnaria* filhoAtual = this->getPtrNoFilho(i);
			if (filhoAtual != nullptr) {
				if (filhoAtual->isVazio()) {
					filhoAtual = nullptr;
				}
				else {
					filhoAtual->conferirNosVazios();
					if (filhoAtual->isVazio()) {
						filhoAtual = nullptr;
					}
				}
			}
	}
}
