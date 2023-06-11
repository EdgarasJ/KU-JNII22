/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "Skritulys.h"

//constructors and destructors
Skritulys::Skritulys() : pi(3.14159) {
	radius = 1.0;
}
Skritulys::Skritulys(double _radius) : pi(3.14159) {
	radius = _radius;
}
Skritulys::~Skritulys(){}
//setters
void Skritulys::setRadius(double _radius) {
	radius = _radius;
}
//getters
double Skritulys::getRadius() {
	return radius;
}
double Skritulys::getArea() {
	return radius * radius * pi;
}
// print info
void Skritulys::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Circle information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Radius" << std::setw(2) << ": " << std::setw(0) << radius << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area" << std::setw(2) << ": " << std::setw(0) << getArea() << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}