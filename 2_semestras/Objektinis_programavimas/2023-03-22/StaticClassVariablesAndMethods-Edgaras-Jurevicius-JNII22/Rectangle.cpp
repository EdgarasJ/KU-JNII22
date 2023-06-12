/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
Revision date 2: 2023-03-22
*/

#include "Rectangle.h"


Point Rectangle::startPoint = new Point(0.0, 0.0);

// constructors and destructors
Rectangle::Rectangle() {
	endPoint.setX(1.0);
	endPoint.setY(1.0);
	calculateValues();
}
Rectangle::Rectangle(double _x, double _y) {
	endPoint.setX(_x);
	endPoint.setY(_y);
	calculateValues();
}
Rectangle::Rectangle(Point _p) {
	endPoint.setX(_p.getX());
	endPoint.setY(_p.getY());
	calculateValues();
}
Rectangle::~Rectangle(){}
// setters
void Rectangle::setEndPoint(double _x, double _y) {
	endPoint.setX(_x);
	endPoint.setY(_y);
	calculateValues();
}
void Rectangle::setEndPoint(Point _p) {
	endPoint.setX(_p.getX());
	endPoint.setY(_p.getY());
	calculateValues();
}
void Rectangle::setStartPoint(double _x, double _y) {
	startPoint.setX(_x);
	startPoint.setY(_y);
}
void Rectangle::setStartPoint(Point _p) {
	startPoint.setX(_p.getX());
	startPoint.setY(_p.getY());
}
// getters
double Rectangle::getPerimeter() {
	calculateValues();
	return perimeter;
}
double Rectangle::getArea() {
	calculateValues();
	return area;
}
Point Rectangle::getStartPoint() {
	return startPoint;
}
Point Rectangle::getEndPoint() {
	return endPoint;
}
// print info
void Rectangle::printInfo() {
	calculateValues();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "Rectangle with points (" << startPoint.getX() << "; " << startPoint.getY() << ") and (" << endPoint.getX() << "; " << endPoint.getY() << ") :" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "Width     :" << width << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "Length    :" << length << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "Area      :" << area << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "Perimeter :" << perimeter << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helper
void Rectangle::calculateValues() {
	width = std::abs(endPoint.getX() - startPoint.getX());
	length = std::abs(endPoint.getY() - startPoint.getY());
	perimeter = 2.0 * (width + length);
	area = length * width;
}