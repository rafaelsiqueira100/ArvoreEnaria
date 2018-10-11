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
	//InfoArvoreEnaria(const InfoArvoreEnaria&) throw();
	friend ostream& operator<< (ostream&, InfoArvoreEnaria&) throw();
	virtual char operator<(const InfoArvoreEnaria&)const throw() = 0;
	virtual char operator>(const InfoArvoreEnaria&)const throw() = 0;
	virtual char operator==(const InfoArvoreEnaria&)const throw() = 0;
	virtual char operator<=(const InfoArvoreEnaria&)const throw() = 0;
	virtual char operator>=(const InfoArvoreEnaria&)const throw() = 0;
	virtual InfoArvoreEnaria& operator=(const InfoArvoreEnaria&)throw() = 0;
	virtual ostream& print(ostream&)const throw() = 0 ;

};
#endif
