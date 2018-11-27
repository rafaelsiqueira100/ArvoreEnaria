
#include "InfoArvoreEnaria.h"


InfoArvoreEnaria::InfoArvoreEnaria()
{
}


InfoArvoreEnaria::~InfoArvoreEnaria()
{
}

ostream& operator<< (ostream& os, InfoArvoreEnaria& info) throw() {
	return((info).print(os));
}