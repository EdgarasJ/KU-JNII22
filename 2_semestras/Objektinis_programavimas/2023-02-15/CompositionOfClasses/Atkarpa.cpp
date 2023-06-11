/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-10
*/


#include "Atkarpa.h"

//constructors and destructor
Atkarpa::Atkarpa() {
	start.setX(0);
	start.setY(0);
	end.setX(0);
	end.setY(0);
}
Atkarpa::Atkarpa(Taskas _start, Taskas _end) {
	start.setX(_start.getX());
	start.setY(_start.getY());
	end.setX(_end.getX());
	end.setY(_end.getY());
}
Atkarpa::Atkarpa(double _startX, double _startY, double _endX, double _endY) {
	start.setX(_startX);
	start.setY(_startY);
	end.setX(_endX);
	end.setY(_endY);
}
Atkarpa::~Atkarpa(){}
// setters
void Atkarpa::setStartPoint(Taskas _start) {
	start.setX(_start.getX());
	start.setY(_start.getY());
}
void Atkarpa::setEndPoint(Taskas _end) {
	end.setX(_end.getX());
	end.setY(_end.getY());
}
void Atkarpa::setStartCoords(double _startX, double _startY) {
	start.setX(_startX);
	start.setY(_startY);
}
void Atkarpa::setEndCoords(double _endX, double _endY) {
	end.setX(_endX);
	end.setY(_endY);
}
// getters
Taskas Atkarpa::getStartPoint() {
	return start;
}
Taskas Atkarpa::getEndPoint() {
	return end;
}
double Atkarpa::getLength() {
	return std::sqrt(((end.getX() - start.getX()) * (end.getX() - start.getX()) + ((end.getY() - start.getY()) * (end.getY() - start.getY())) ));
}
// print info
void Atkarpa::printInfo() {
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
	std::cout << "Line segment info:" << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Start point" << std::setw(0) << ": ";
	start.printCoordsOnly();
	std::cout << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "End point" << std::setw(0) << ": ";
	end.printCoordsOnly();
	std::cout << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Length" << std::setw(0) << ": " << getLength() << std::endl;
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
}
