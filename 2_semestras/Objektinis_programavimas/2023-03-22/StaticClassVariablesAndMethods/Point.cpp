/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
*/

#include "Point.h"

//constructors and destructor
Point::Point() {
	x = 0.0;
	y = 0.0;
}
Point::Point(double _x, double _y) {
	x = _x;
	y = _y;
}
Point::Point(Point &p) {
	x = p.getX();
	y = p.getY();
}
Point::Point(Point* p) {
	x = p->getX();
	y = p->getY();
}
Point::~Point(){}
//setters
void Point::setX(double _x) {
	x = _x;
}
void Point::setY(double _y) {
	y = _y;
}
//getters
double Point::getX() {
	return x;
}
double Point::getY() {
	return y;
}