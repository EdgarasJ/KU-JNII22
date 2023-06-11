/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-10
*/

#pragma once
#include <iomanip>
#include <iomanip>
#include "Taskas.h"
#include <cmath>

class Atkarpa
{
public:
	//constructors and destructor
	Atkarpa();
	Atkarpa(Taskas, Taskas);
	Atkarpa(double, double, double, double);
	~Atkarpa();
	// setters
	void setStartPoint(Taskas);
	void setEndPoint(Taskas);
	void setStartCoords(double, double);
	void setEndCoords(double, double);
	// getters
	Taskas getStartPoint();
	Taskas getEndPoint();
	double getLength();
	// print info
	void printInfo();
private:
	Taskas start;
	Taskas end;
};

