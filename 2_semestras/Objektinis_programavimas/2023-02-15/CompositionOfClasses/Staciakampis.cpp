/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (Composition of Classes)
Revision date 1: 2023-02-04
*/


#include "Staciakampis.h"

// constructors and destructor
Staciakampis::Staciakampis(Taskas _p1, Taskas _p2, Taskas _p3, Taskas _p4) {
	errorSet = false;
	
	point1.setX(_p1.getX());
	point1.setY(_p1.getY());
	point2.setX(_p2.getX());
	point2.setY(_p2.getY());
	point3.setX(_p3.getX());
	point3.setY(_p3.getY());
	point4.setX(_p4.getX());
	point4.setY(_p4.getY());
	
	edgesLength = {};
	
	if (!isRectangle()){
		std::string msg = "Error: Figure defined by coordinates ";
		msg.append(figureCoordsStr());
		msg.append("is not a rectangle.");
		printError(msg);
		errorSet = true;
	}
}
Staciakampis::~Staciakampis(){}
//getters
bool Staciakampis::getErrorFlag() {
	return errorSet;
}
//methods for area and perimeter
double Staciakampis::getArea() {
	if (edgesLength.size() == 1) {
		return edgesLength[0] * edgesLength[0];
	}
	else {
		return edgesLength[0] * edgesLength[1];
	}
}
double Staciakampis::getPerimeter() {
	if (edgesLength.size() == 1) {
		return edgesLength[0] * 4;
	}
	else {
		return (edgesLength[0] + edgesLength[1]) * 2;
	}
}
//print info
void Staciakampis::printInfo() {
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
	std::cout << "Rectangles with coordinates " << figureCoordsStr() << " :" << std::endl;
	std::cout << std::setw(20) << "Area is" << std::fixed << std::setprecision(3) << std::setw(0) << ": " << getArea() << std::endl;
	std::cout << std::setw(20) << "Perimeter is" << std::fixed << std::setprecision(3) << std::setw(0) << ": " << getPerimeter() << std::endl;
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
}

// helper functions
bool Staciakampis::isRectangle() {
	Taskas points[4] = { point1, point2, point3, point4 };
	int rightAmount[4] = { 0, 0, 0, 0};
	for (int i = 0; i < 4; i++) {
		
		if (isRightAngle(points[i], points[(i + 1) % 4], points[(i + 2) % 4])) {
			rightAmount[i]++;
		}
		if (isRightAngle(points[i], points[(i + 1) % 4], points[(i + 3) % 4])) {
			rightAmount[i]++;
		}
		if (isRightAngle(points[i], points[(i + 2) % 4], points[(i + 3) % 4])) {
			rightAmount[i]++;
		}
	}
	
	if (rightAmount[0] == 1 && rightAmount[1] == 1 && rightAmount[2] == 1 && rightAmount[3] == 1) {
		return true;
	}
	return false;
}
void Staciakampis::printError(std::string errMsg) {
	std::cout << std::setw(0) << errMsg << std::endl;
}
bool Staciakampis::isRightAngle(Taskas _intersection, Taskas _end1, Taskas _end2) {
	double vect1X, vect1Y, vect2X, vect2Y, vect1Length, vect2Length;
	vect1X = _end1.getX() - _intersection.getX();
	vect1Y = _end1.getY() - _intersection.getY();
	vect2X = _end2.getX() - _intersection.getX();
	vect2Y= _end2.getY() - _intersection.getY();
	vect1Length = std::sqrt(vect1X * vect1X + vect1Y * vect1Y);
	vect2Length = std::sqrt(vect2X * vect2X + vect2Y * vect2Y);

	double cosAlpha = (vect1X * vect2X + vect1Y * vect2Y) / (vect1Length * vect2Length);
	
	if (cosAlpha == 0.0) {
		if (std::find(edgesLength.begin(), edgesLength.end(), vect1Length) == edgesLength.end()) {
			edgesLength.push_back(vect1Length);
		}
		if (std::find(edgesLength.begin(), edgesLength.end(), vect2Length) == edgesLength.end()) {
			edgesLength.push_back(vect2Length);
		}
		return true;
	}
	return false;
}
std::string Staciakampis::figureCoordsStr() {
	std::string str = " [ (";
	str.append(std::to_string(point1.getX()));
	str.append(", ");
	str.append(std::to_string(point1.getY()));
	str.append("), (");
	str.append(std::to_string(point2.getX()));
	str.append(", ");
	str.append(std::to_string(point2.getY()));
	str.append("), (");
	str.append(std::to_string(point3.getX()));
	str.append(", ");
	str.append(std::to_string(point3.getY()));
	str.append("), (");
	str.append(std::to_string(point4.getX()));
	str.append(", ");
	str.append(std::to_string(point4.getY()));
	str.append(") ]");
	return str;
}