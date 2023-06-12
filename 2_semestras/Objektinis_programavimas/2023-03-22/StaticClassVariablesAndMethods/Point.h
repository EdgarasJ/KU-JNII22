/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
*/

#pragma once

class Point
{
private:
	double x;
	double y;
public:
	//constructors and destructor
	Point();
	Point(double, double);
	Point(Point&);
	Point(Point*);
	~Point();
	//setters
	void setX(double);
	void setY(double);
	//getters
	double getX();
	double getY();
};

