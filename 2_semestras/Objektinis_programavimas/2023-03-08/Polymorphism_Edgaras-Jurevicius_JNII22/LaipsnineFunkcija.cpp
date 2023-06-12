/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "LaipsnineFunkcija.h"

//constructors and destructor
LaipsnineFunkcija::LaipsnineFunkcija() : Funkcija() {
	n = 1.0;
	setFx();
}
LaipsnineFunkcija::LaipsnineFunkcija(double _n) : Funkcija() {
	n = _n;
	setFx();
}
LaipsnineFunkcija::LaipsnineFunkcija(double _x, double _n) : Funkcija(_x) {
	n = _n;
	setFx();
}
LaipsnineFunkcija::~LaipsnineFunkcija(){}
// setters
void LaipsnineFunkcija::setX(double _x) {
	x = _x;
	setFx();
}
void LaipsnineFunkcija::setN(double _n) {
	n = _n;
	setFx();
}
void LaipsnineFunkcija::setFx() {
	fx = pow(x, n);
}
// getters
double LaipsnineFunkcija::getN() {
	return n;
}
void LaipsnineFunkcija::getFx() {
	setFx();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Function F(" << x << ") = x ^ " << n << " result is " << fx << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}