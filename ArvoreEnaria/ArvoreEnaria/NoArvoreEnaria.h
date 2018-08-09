#pragma once

#ifndef NOARVOREENARIA_H_INCLUDED
#define NOARVOREENARIA_H_INCLUDED
#include "InfoArvoreEnaria.h"

class NoArvoreEnaria
{
public:
	NoArvoreEnaria();
	~NoArvoreEnaria();
private:
	InfoArvoreEnaria * * vetPtrInfo;
	NoArvoreEnaria ** vetPtrNo;
};

#endif