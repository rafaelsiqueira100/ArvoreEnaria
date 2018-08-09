#pragma once

#ifndef ARVOREENARIA_H_INCLUDED
#define ARVOREENARIA_H_INCLUDED
#include "NoArvoreEnaria.h"
#include "InfoArvoreEnaria.h"
#include <stdio.h>
class ArvoreEnaria
{
public:
	ArvoreEnaria(unsigned int);
	~ArvoreEnaria();
	void inserir(InfoArvoreEnaria) throw(char*);
	ostream& operator<< (ostream&) throw();

private:
	NoArvoreEnaria * raiz;
	
};
#endif
