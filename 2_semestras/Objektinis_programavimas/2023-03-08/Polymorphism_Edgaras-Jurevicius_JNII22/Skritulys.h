/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include "GeometrineFigura.h"
#include <iostream>
#include <iomanip>

class Skritulys :
    public GeometrineFigura
{
private:
    double r;
	double pi;
	//helper
	void calculateArea();
public:
	//constructor and destructor
	Skritulys();
	Skritulys(double);
	~Skritulys();
	//setters
	void setR(double);
	//getters
	double getR();
	//print
	void printArea();
};

