/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1: 2023-03-08
*/

#include "Trikampis.h"

//constructors and destructor
Trikampis::Trikampis() {
	base = 1.0;
	heigth = 1.0;
	calculateArea();
}
Trikampis::Trikampis(double _base, double _heigth) {
	base = _base;
	heigth = _heigth;
	calculateArea();
}
Trikampis::~Trikampis(){}
//setters
void Trikampis::setBase(double _base) {
	base = _base;
	calculateArea();
}
void Trikampis::setHeigth(double _heigth) {
	heigth = _heigth;
	calculateArea();
}
//getters
double Trikampis::getBase() {
	return base;
}
double Trikampis::getHeigth() {
	return heigth;
}
//print
void Trikampis::printArea() {
	calculateArea();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Triangle with base " << base << " and heigth " << heigth << " area is " << area << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helper
void Trikampis::calculateArea() {
	area = (base * heigth) / 2.0;
}