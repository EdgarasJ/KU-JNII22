/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <iomanip>

class Taskas
{
public:
	//constructors and destructor
	Taskas(double, double);
	Taskas();
	~Taskas();
	//setters
	void setX(double);
	void setY(double);
	//getters
	double getX();
	double getY();
	// print info
	void printCoordsOnly();
	void printInfo();
private:
	double x;
	double y;
};

