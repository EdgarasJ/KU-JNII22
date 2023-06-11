/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

class Vektorius2D
{
protected:
	double x;
	double y;
public:
	//constructors and destructor
	Vektorius2D();
	Vektorius2D(double, double);
	~Vektorius2D();
	//setters
	void setX(double);
	void setY(double);
	//getters
	double getX();
	double getY();
	double getLength();
	// print info
	void printInfo();
};

