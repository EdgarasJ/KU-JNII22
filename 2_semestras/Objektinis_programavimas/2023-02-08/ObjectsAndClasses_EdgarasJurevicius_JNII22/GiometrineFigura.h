/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <iomanip>

class GiometrineFigura
{
public:
	// constructors, destructor
	GiometrineFigura(unsigned int, bool);
	GiometrineFigura();
	~GiometrineFigura();
	// setters
	void setNumberOfEdges(unsigned int);
	void setIsRegularFigure(bool);
	// getters
	unsigned int getNumberOfEdges();
	bool getIsRegularFigure();
	// print info about Figure
	void printInfo();
private:
	unsigned int numberOfEdges;
	bool isRegular;
};

