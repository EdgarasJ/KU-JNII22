/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include <iomanip>
#include <iostream>

class GeometrineFigura
{
protected:
	double perimeter;
	double area;
public:
	//constructors and destructor
	GeometrineFigura();
	GeometrineFigura(double, double);
	~GeometrineFigura();
	//setters
	void setPerimeter(double);
	void setArea(double);
	// getters
	double getPerimeter();
	double getArea();
	//print info
	void printInfo();
};

