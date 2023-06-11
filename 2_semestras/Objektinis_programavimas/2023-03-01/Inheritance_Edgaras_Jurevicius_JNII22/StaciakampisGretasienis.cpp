/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-03-01
*/

#include "StaciakampisGretasienis.h"

//constructors and destructor
StaciakampisGretasienis::StaciakampisGretasienis() : Staciakampis() {
	height = 4.0;
	calculatePerimeter();
	calculateArea();
	calculateVolume();
}
StaciakampisGretasienis::StaciakampisGretasienis(double _width, double _length, double _heigth) : Staciakampis(_width, _length) {
	height = _heigth;
	calculatePerimeter();
	calculateArea();
	calculateVolume();
}
StaciakampisGretasienis::~StaciakampisGretasienis(){}
//setters
void StaciakampisGretasienis::setWidth(double _width) {
	width = _width;
	calculatePerimeter();
	calculateArea();
	calculateVolume();
}
void StaciakampisGretasienis::setLength(double _length) {
	length = _length;
	calculatePerimeter();
	calculateArea();
	calculateVolume();
}
void StaciakampisGretasienis::setHeigth(double _heigth) {
	height = _heigth;
	calculatePerimeter();
	calculateArea();
	calculateVolume();
}
//getters
double StaciakampisGretasienis::getHeight() {
	return height;
}
double StaciakampisGretasienis::getVolume() {
	return volume;
}
//print info
void StaciakampisGretasienis::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Cuboid information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Length" << std::setw(2) << ": " << std::setw(0) << length << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Width" << std::setw(2) << ": " << std::setw(0) << width << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Heigth" << std::setw(2) << ": " << std::setw(0) << height << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Perimeter" << std::setw(2) << ": " << std::setw(0) << perimeter << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area" << std::setw(2) << ": " << std::setw(0) << area << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Volume" << std::setw(2) << ": " << std::setw(0) << volume << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helper fuctions
void StaciakampisGretasienis::calculatePerimeter() {
	perimeter = 4.0 * (width + length + height);
}
void StaciakampisGretasienis::calculateArea() {
	area = 2.0 * (width * length + width * height + length * height);
}
void StaciakampisGretasienis::calculateVolume() {
	volume = width * length * height;
}