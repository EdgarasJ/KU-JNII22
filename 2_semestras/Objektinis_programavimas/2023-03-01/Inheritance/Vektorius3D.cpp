/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "Vektorius3D.h"

//constructors and destructor
Vektorius3D::Vektorius3D() : Vektorius2D() {
	z = 3.0;
}
Vektorius3D::Vektorius3D(double _x, double _y, double _z) : Vektorius2D(_x, _y) {
	z = _z;
}
Vektorius3D::~Vektorius3D(){}
//setters
void Vektorius3D::setZ(double _z) {
	z = _z;
}
//getters
double Vektorius3D::getZ() {
	return z;
}
double Vektorius3D::getLength() {
	return std::sqrt(x * x + y * y + z * z);
}
//print info
void Vektorius3D::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "3D Vector information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "X coordinates" << std::setw(2) << ": " << std::setw(0) << x << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Y coordinates" << std::setw(2) << ": " << std::setw(0) << y << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Z coordinates" << std::setw(2) << ": " << std::setw(0) << z << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Vector length" << std::setw(2) << ": " << std::setw(0) << getLength() << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}