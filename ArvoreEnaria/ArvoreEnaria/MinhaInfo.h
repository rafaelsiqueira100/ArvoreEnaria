#pragma once

#ifndef MINHAINFO_H_INCLUDED
#define MINHAINFO_H_INCLUDED
#include "InfoArvoreEnaria.h"
#include <iostream>
using namespace std;
class MinhaInfo : public InfoArvoreEnaria
{
public:
	MinhaInfo();
	MinhaInfo(int);
	MinhaInfo(const InfoArvoreBinariaAVL&) throw();
	friend ostream& operator<< (ostream&, const MinhaInfo&) throw();
	int getValor() const throw();
	void setValor(int) throw();
	char operator<(const InfoArvoreBinariaAVL&)const throw() ;
	char operator>(const InfoArvoreBinariaAVL&)const throw() ;
	char operator==(const InfoArvoreBinariaAVL&)const throw();
	char operator<=(const InfoArvoreBinariaAVL&)const throw();
	char operator>=(const InfoArvoreBinariaAVL&)const throw();
	void operator=(const InfoArvoreBinariaAVL&)throw();
	ostream& print(ostream&) const throw() ;
	
private:
	int valor;
	
};
#endif

