/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "TiesineFunkcija.h"

//constructors and destructor
TiesineFunkcija::TiesineFunkcija() : Funkcija() {
	k = 1.0;
	b = 0.0;
	setFx();
}
TiesineFunkcija::TiesineFunkcija(double _k, double _b) : Funkcija() {
	k = _k;
	b = _b;
	setFx();
}
TiesineFunkcija::TiesineFunkcija(double _x, double _k, double _b) : Funkcija(_x) {
	k = _k;
	b = _b;
	setFx();
}
TiesineFunkcija::~TiesineFunkcija(){}
// setters
void TiesineFunkcija::setX(double _x) {
	x = _x;
	setFx();
}
void TiesineFunkcija::setK(double _k) {
	k = _k;
	setFx();
}
void TiesineFunkcija::setB(double _b) {
	b = _b;
	setFx();
}
void TiesineFunkcija::setFx() {
	fx = k * x + b;
}
// getters
double TiesineFunkcija::getK() {
	return k;
}
double TiesineFunkcija::getB() {
	return b;
}
void TiesineFunkcija::getFx() {
	setFx();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Function F(" << x << ") = " << k << " * x + " << b << " result is " << fx << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}