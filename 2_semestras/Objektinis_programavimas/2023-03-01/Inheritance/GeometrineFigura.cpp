/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "GeometrineFigura.h"

//constructors and destructor
GeometrineFigura::GeometrineFigura() {
	perimeter = 0.0;
	area = 0.0;
}
GeometrineFigura::GeometrineFigura(double _perimeter, double _area) {
	perimeter = _perimeter;
	area = _area;
}
GeometrineFigura::~GeometrineFigura(){}
//setters
void GeometrineFigura::setPerimeter(double _perimeter) {
	perimeter = _perimeter;
}
void GeometrineFigura::setArea(double _area) {
	area = _area;
}
// getters
double GeometrineFigura::getPerimeter() {
	return perimeter;
}
double GeometrineFigura::getArea() {
	return area;
}
//print info
void GeometrineFigura::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Figure information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Perimeter" << std::setw(2) << ": " << std::setw(0) << perimeter << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area" << std::setw(2) << ": " << std::setw(0) << area << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}