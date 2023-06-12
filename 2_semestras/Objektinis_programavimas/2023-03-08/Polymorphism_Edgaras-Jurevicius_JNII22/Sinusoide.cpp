/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "Sinusoide.h"

//constructors and destructor
Sinusoide::Sinusoide() : Funkcija(0.0) {
	setFx();
}
Sinusoide::Sinusoide(double _x) : Funkcija(_x) {
	setFx();
}
Sinusoide::~Sinusoide(){}
// setters
void Sinusoide::setFx() {
	fx = sin(x);
}
// getters
void Sinusoide::getFx() {
	setFx();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Function F(" << x << ") = sin(x) result is " << fx << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}