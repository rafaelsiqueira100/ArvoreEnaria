#include "stdafx.h"
#include "MinhaInfo.h"


MinhaInfo::MinhaInfo(int vlr) {
	this->valor = vlr;
}
ostream& MinhaInfo::print(ostream& os)const throw()  {
	return os << this->valor;
}