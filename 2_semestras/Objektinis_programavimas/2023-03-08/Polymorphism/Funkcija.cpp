/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "Funkcija.h"

//constructors and destructor
Funkcija::Funkcija() {
	x = 1.0;
	setFx();
}
Funkcija::Funkcija(double _x) {
	x = _x;
	setFx();
}
Funkcija::~Funkcija(){}
// setters
void Funkcija::setX(double _x) {
	x = _x;
	setFx();
}
void Funkcija::setFx() {
	fx = x;
}
// getters
double Funkcija::getX() {
	return x;
}
//print
void Funkcija::getFx() {
	std::cout << " " << std::endl;
}