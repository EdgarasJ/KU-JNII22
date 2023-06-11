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

class Skritulys
{
protected:
	double radius;
private:
	double pi;
public:
	//constructors and destructors
	Skritulys();
	Skritulys(double);
	~Skritulys();
	//setters
	void setRadius(double);
	//getters
	double getRadius();
	double getArea();
	// print info
	void printInfo();
};

