#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreEnaria.h"
using namespace std;
class MinhaInfo : public InfoArvoreEnaria
{
public:
	MinhaInfo();
	MinhaInfo(int);
	MinhaInfo(const InfoArvoreEnaria&) throw();
	friend ostream& operator<< (ostream&, const MinhaInfo&) throw();
	int getValor() const throw();
	void setValor(int) throw();
	char operator<(const InfoArvoreEnaria&)const throw();
	char operator>(const InfoArvoreEnaria&)const throw();
	char operator==(const InfoArvoreEnaria&)const throw();
	char operator<=(const InfoArvoreEnaria&)const throw();
	char operator>=(const InfoArvoreEnaria&)const throw();
	InfoArvoreEnaria& operator=(const InfoArvoreEnaria&)throw();
	ostream& print(ostream&) const throw();

private:
	int valor;

};
#endif

