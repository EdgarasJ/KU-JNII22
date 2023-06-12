/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
Revision date 2: 2023-03-22
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Point.h"

class Rectangle
{
private:
	static Point startPoint;
	Point endPoint;
	double perimeter;
	double area;
	double width;
	double length;
	//helper
	void calculateValues();
public:
	// constructors and destructors
	Rectangle();
	Rectangle(double, double);
	Rectangle(Point);
	~Rectangle();
	// setters
	void setEndPoint(double, double);
	void setEndPoint(Point);
	static void setStartPoint(double, double);
	static void setStartPoint(Point);
	// getters
	double getPerimeter();
	double getArea();
	static Point getStartPoint();
	Point getEndPoint();
	// print info
	void printInfo();
};

