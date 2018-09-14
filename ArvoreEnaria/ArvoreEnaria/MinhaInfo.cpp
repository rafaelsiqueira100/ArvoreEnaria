
#include "MinhaInfo.h"
MinhaInfo::MinhaInfo() : valor(0) {}

MinhaInfo::MinhaInfo(int vlr) {
	this->valor = vlr;
}
MinhaInfo::MinhaInfo(const InfoArvoreBinariaAVL& outra) {
	new MinhaInfo(((const MinhaInfo&)outra).valor);
}

ostream& MinhaInfo::print(ostream& os)const throw()  {
	return os << this->valor;
}
int MinhaInfo::getValor()const throw() {
	return this->valor;
}
void MinhaInfo::setValor(int novoValor) throw() {
	this->valor = (novoValor);
}
char MinhaInfo::operator<(const InfoArvoreBinariaAVL& outra)const throw(){
	return this->valor <((const MinhaInfo&) outra).getValor();
}
char MinhaInfo::operator>(const InfoArvoreBinariaAVL& outra)const throw() {
	return this->valor > ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator==(const InfoArvoreBinariaAVL& outra)const throw() {
	return this->valor == ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator<=(const InfoArvoreBinariaAVL& outra)const throw() {
	return this->valor <= ((const MinhaInfo&)outra).getValor();
}
char MinhaInfo::operator>=(const InfoArvoreBinariaAVL& outra)const throw() {
	return this->valor >= ((const MinhaInfo&)outra).getValor();
}
void MinhaInfo::operator=(const InfoArvoreBinariaAVL& outra)throw() {
	valor = (((const MinhaInfo&)outra).valor);
}
