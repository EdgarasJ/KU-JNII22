/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-08
Revision date 2: 2023-02-09
*/


#include "Skritulys.h"

//constructors and destructors
Skritulys::Skritulys(const Skritulys& _circle) : pi(3.14) {
	radius = _circle.radius;
}
Skritulys::Skritulys() : pi (3.14) {
	radius = 0.0;
}
Skritulys::Skritulys(double _radius) : pi(3.14) {
	radius = _radius;
}
Skritulys::~Skritulys(){}
// seters
void Skritulys::setRadius(double _radius) {
	radius = _radius;
};
// getters
double Skritulys::getRadius() {
	return radius;
}
double Skritulys::getArea() {
	return pi * radius * radius;
}
// print info
void Skritulys::printInfo() {
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
	std::cout << std::setw(15) << "Circle radius" << std::setw(0) << ": " << std::fixed << std::setprecision(2) << radius << std::endl;
	std::cout << std::setw(15) << "Circle area" << std::setw(0) << ": " << std::fixed << std::setprecision(2) << getArea() << std::endl;
}