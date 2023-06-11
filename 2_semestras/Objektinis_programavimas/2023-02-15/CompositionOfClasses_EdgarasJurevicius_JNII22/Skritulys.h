/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-08
Revision date 2: 2023-02-09
*/

#pragma once
#include <iostream>
#include <iomanip>

class Skritulys
{
public:
	//constructors and destructors
	Skritulys(const Skritulys&);
	Skritulys();
	Skritulys(double);
	~Skritulys();
	// seters
	void setRadius(double);
	// getters
	double getRadius();
	double getArea();
	// print info
	void printInfo();
private:
	double radius;
	const double pi;
};

