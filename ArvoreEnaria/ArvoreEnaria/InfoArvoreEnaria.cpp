#include "stdafx.h"
#include "InfoArvoreEnaria.h"


InfoArvoreEnaria::InfoArvoreEnaria()
{
}


InfoArvoreEnaria::~InfoArvoreEnaria()
{
}

ostream& operator<< (ostream& os, const InfoArvoreEnaria& info) throw() {
	return os << info.print(os);
}