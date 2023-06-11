/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "Ritinys.h"

//constructors and destructor
Ritinys::Ritinys() : Skritulys() {
	altitude = 2.0;
}
Ritinys::Ritinys(double _alt) : Skritulys() {
	altitude = _alt;
}
Ritinys::Ritinys(double _radius, double _alt) : Skritulys(_radius) {
	altitude = _alt;
}
Ritinys::~Ritinys(){}
// setters
void Ritinys::setAltitude(double _alt) {
	altitude = _alt;
}
// getters
double Ritinys::getAltitude() {
	return altitude;
}
double Ritinys::getVolume() {
	return altitude * getArea();
}
//print info
void Ritinys::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Cylinder information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Radius" << std::setw(2) << ": " << std::setw(0) << radius << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area" << std::setw(2) << ": " << std::setw(0) << getArea() << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Altitude" << std::setw(2) << ": " << std::setw(0) << altitude << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Volume" << std::setw(2) << ": " << std::setw(0) << getVolume() << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}