#pragma once
#ifndef INFOARVOREENARIA_H_INCLUDED
#define INFOARVOREENARIA_H_INCLUDED
#include <iostream>
using namespace std;
class InfoArvoreEnaria
{
public:
	InfoArvoreEnaria();
	~InfoArvoreEnaria();
	InfoArvoreEnaria getInfo() throw();
	friend ostream& operator<< (ostream&, const InfoArvoreEnaria&) throw();
	virtual ostream& print(ostream&)const = 0 ;

};
#endif
