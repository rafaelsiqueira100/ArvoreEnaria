#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreEnaria.h"
class MinhaInfo : public InfoArvoreEnaria
{
public:
	MinhaInfo();
	~MinhaInfo();
private:
	MinhaInfo getInfo() throw() const;
};
#endif

