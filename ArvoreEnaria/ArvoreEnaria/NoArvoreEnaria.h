#pragma once

#ifndef NOARVOREENARIA_H_INCLUDED
#define NOARVOREENARIA_H_INCLUDED
#include "InfoArvoreEnaria.h"

#include <iostream>
using namespace std;
class NoArvoreEnaria
{
public:
	NoArvoreEnaria(unsigned int)throw(char*);
	~NoArvoreEnaria();
	NoArvoreEnaria(const NoArvoreEnaria&) throw(char*);
	friend ostream& operator<< (ostream&, const NoArvoreEnaria&) throw();
	NoArvoreEnaria* getPtrNoFilho(unsigned int) const throw();
	void setPtrNoFilho(NoArvoreEnaria* novoNo, unsigned int indFilho) const throw();
	InfoArvoreEnaria* getPtrInfo(unsigned int) const throw();
	int getNumInfos()const throw();
	char colocarVetorOrdem(InfoArvoreEnaria* info) throw();
	char removerVetorOrdem(InfoArvoreEnaria* info)throw();
	char isCheio() const throw();
	bool isVazio() const throw();
	char isFolha() const throw();
	char haInfo(const InfoArvoreEnaria&) const throw();
	char operator==(const NoArvoreEnaria&)const throw();

private:
	InfoArvoreEnaria ** vetPtrInfo;
	NoArvoreEnaria ** vetPtrNo;
	int numInfos;
	InfoArvoreEnaria& acharInfoPorLugar(InfoArvoreEnaria&, unsigned int) throw(char*);
	NoArvoreEnaria* conferirNosVazios();
	void reoordenarInfos() throw();
	char reestruturando;
};

#endif