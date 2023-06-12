/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1: 2023-03-08
*/

#include "Skritulys.h"

//constructor and destructor
Skritulys::Skritulys() : pi(3.14159) {
	r = 1.0;
	calculateArea();
}
Skritulys::Skritulys(double _r) : pi(3.14159) {
	r = _r;
	calculateArea();
}
Skritulys::~Skritulys(){}
//setters
void Skritulys::setR(double _r) {
	r = _r;
	calculateArea();
}
//getters
double Skritulys::getR() {
	return r;
}
//print
void Skritulys::printArea() {
	calculateArea();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Circle with radius " << r << " area is " << area << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helpers
void Skritulys::calculateArea() {
	area = r * r * pi;
}