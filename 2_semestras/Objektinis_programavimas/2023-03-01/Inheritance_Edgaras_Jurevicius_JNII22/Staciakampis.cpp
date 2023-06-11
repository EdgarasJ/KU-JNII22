/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
Revision date 2: 2023-03-01
*/

#include "Staciakampis.h"

//constructors and destructor
Staciakampis::Staciakampis() : GeometrineFigura() {
	length = 3.0;
	width = 2.0;
	calculatePerimeter();
	calculateArea();
}
Staciakampis::Staciakampis(double _length, double _width) : GeometrineFigura() {
	length = _length;
	width = _width;
	calculatePerimeter();
	calculateArea();
}
Staciakampis::~Staciakampis(){}
// setters
void Staciakampis::setLength(double _length) {
	length = _length;
	calculatePerimeter();
	calculateArea();
}
void Staciakampis::setWidth(double _width) {
	width = _width;
	calculatePerimeter();
	calculateArea();
}
// getters
double Staciakampis::getLength() {
	return length;
}
double Staciakampis::getWidth() {
	return width;
}
// print info
void Staciakampis::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Rectangle information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Length" << std::setw(2) << ": " << std::setw(0) << length << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Width" << std::setw(2) << ": " << std::setw(0) << width << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Perimeter" << std::setw(2) << ": " << std::setw(0) << perimeter << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area" << std::setw(2) << ": " << std::setw(0) << area << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}

// helper functions
void Staciakampis::calculatePerimeter() {
	perimeter = 2 * (length + width);
}
void Staciakampis::calculateArea() {
	area = length * width;
}