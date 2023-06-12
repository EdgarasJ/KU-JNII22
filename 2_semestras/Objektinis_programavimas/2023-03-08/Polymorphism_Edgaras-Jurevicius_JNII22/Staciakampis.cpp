/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1: 2023-03-08
*/

#include "Staciakampis.h"

//constructors and destructor
Staciakampis::Staciakampis(){
	length = 1.0;
	width = 1.0;
	calculateArea();
}
Staciakampis::Staciakampis(double _length, double _width) {
	length = _length;
	width = _width;
	calculateArea();
}
Staciakampis::~Staciakampis(){}
//setters
void Staciakampis::setLength(double _length) {
	length = _length;
	calculateArea();
}
void Staciakampis::setWidth(double _width) {
	width = _width;
	calculateArea();
}
//getters
double Staciakampis::getLength() {
	return length;
}
double Staciakampis::getWidth() {
	return width;
}
//print
void Staciakampis::printArea(){
	calculateArea();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Rectangle with length " << length << " and width " << width << " area is " << area << "." << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helper
void Staciakampis::calculateArea() {
	area = length * width;
}