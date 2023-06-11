/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1:
*/

#include "Taskas.h"

//constructors and destructor
Taskas::Taskas(double _x, double _y) {
	x = _x;
	y = _y;
}
Taskas::Taskas() {
	x = 1.0;
	y = 1.0;
}
Taskas::~Taskas(){}
//setters
void Taskas::setX(double _x) {
	x = _x;
}
void Taskas::setY(double _y) {
	y = _y;
}
//getters
double Taskas::getX() {
	return x;
}
double Taskas::getY() {
	return y;
}
// print info
void Taskas::printCoordsOnly() {
	std::cout << std::setw(0) << "(" << x << ", " << y << ")";
}
void Taskas::printInfo() {
	std::cout << "Point coordinates" << ": ";
	printCoordsOnly();
	std::cout << std::endl;
}