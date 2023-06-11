/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1:
*/

#pragma once
#include "Taskas.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>

class Staciakampis
{
public:
	// constructors and destructor
	Staciakampis(Taskas, Taskas, Taskas, Taskas);
	~Staciakampis();
	//getters
	bool getErrorFlag();
	//methods for area and perimeter
	double getArea();
	double getPerimeter();
	//print info
	void printInfo();
private:
	// data
	Taskas point1, point2, point3, point4;
	std::vector<double> edgesLength;
	bool errorSet;
	// helper functions
	bool isRectangle();
	void printError(std::string);
	bool isRightAngle(Taskas, Taskas, Taskas);
	std::string figureCoordsStr();
};

