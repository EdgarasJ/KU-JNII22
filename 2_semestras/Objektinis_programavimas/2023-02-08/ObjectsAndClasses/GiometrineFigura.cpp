/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1:
*/


#include "GiometrineFigura.h"

// constructors, destructor
GiometrineFigura::GiometrineFigura(unsigned int _edges, bool _isRegular) {
	numberOfEdges = _edges;
	isRegular = _isRegular;
}

GiometrineFigura::GiometrineFigura() {
	numberOfEdges = 3;
	isRegular = true;
}

GiometrineFigura::~GiometrineFigura() {}

// setters
void GiometrineFigura::setNumberOfEdges(unsigned int _edges) {
	numberOfEdges = _edges;
}

void GiometrineFigura::setIsRegularFigure(bool _isRegular) {
	isRegular = _isRegular;
}

// getters
unsigned int GiometrineFigura::getNumberOfEdges() {
	return numberOfEdges;
}

bool GiometrineFigura::getIsRegularFigure() {
	return isRegular;
}

// print info about Figure
void GiometrineFigura::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
	std::cout << std::setw(28) << "Figuros krastiniu skaicius" << std::setw(0) << ": " << numberOfEdges << std::endl;
	std::cout << std::setw(28) << "Ar figura yra taisyklinga" << std::setw(0) << ": ";
	if (isRegular) {
		std::cout << "Taip" << std::endl;
	}
	else {
		std::cout << "Ne" << std::endl;
	}
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
}