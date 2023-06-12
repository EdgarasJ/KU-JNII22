/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1: 2023-03-08
*/

#pragma once
class GeometrineFigura
{
protected:
	double area;
public :
	//setters
	void setArea(double);
	//helper
	virtual void calculateArea() =0;
	//print
	virtual void printArea() =0;
};

