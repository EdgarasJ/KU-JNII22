/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "Vektorius2D.h"

//constructors and destructor
Vektorius2D::Vektorius2D() {
	x = 4.0;
	y = 3.0;
}
Vektorius2D::Vektorius2D(double _x, double _y) {
	x = _x;
	y = _y;
}
Vektorius2D::~Vektorius2D(){}
//setters
void Vektorius2D::setX(double _x) {
	x = _x;
}
void Vektorius2D::setY(double _y) {
	y = _y;
}
//getters
double Vektorius2D::getX() {
	return x;
}
double Vektorius2D::getY() {
	return y;
}
double Vektorius2D::getLength() {
	return std::sqrt(x * x + y * y);
}
// print info
void Vektorius2D::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "2D Vector information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "X coordinates" << std::setw(2) << ": " << std::setw(0) << x << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Y coordinates" << std::setw(2) << ": " << std::setw(0) << y << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Vector length" << std::setw(2) << ": " << std::setw(0) << getLength() << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
