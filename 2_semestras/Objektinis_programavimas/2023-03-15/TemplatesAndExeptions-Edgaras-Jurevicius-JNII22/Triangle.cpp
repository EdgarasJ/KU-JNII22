/*
Author: Edgaras Jurevicius
Date: 2023-03-08
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1:
*/

#include "Triangle.h"

//constructors and destructor
Triangle::Triangle() {
	edge1 = 1.0;
	edge2 = 1.0;
	edge3 = 1.0;
	checkErrors();
}
Triangle::Triangle(double _edge1, double _edge2, double _edge3) {
	edge1 = _edge1;
	edge2 = _edge2;
	edge3 = _edge3;
	checkErrors();
}
Triangle::~Triangle(){}
//setters
void Triangle::setEdge1(double _edge1) {
	edge1 = _edge1;
	checkErrors();
}
void Triangle::setEdge2(double _edge2) {
	edge2 = _edge2;
	checkErrors();
}
void Triangle::setEdge3(double _edge3) {
	edge3 = _edge3;
	checkErrors();
}
void Triangle::setEdges(double _edge1, double _edge2, double _edge3) {
	edge1 = _edge1;
	edge2 = _edge2;
	edge3 = _edge3;
	checkErrors();
}
//getters
double Triangle::getEdge1() {
	return edge1;
}
double Triangle::getEdge2() {
	return edge2;
}
double Triangle::getEdge3() {
	return edge3;
}
//helper
void Triangle::checkErrors() {
	if (edge1 > edge2 + edge3) {
		throw TooLong(edge1, "Edge 1");
	}
	if (edge2 > edge1 + edge3) {
		throw TooLong(edge2, "Edge 2");
	}
	if (edge3 > edge2 + edge1) {
		throw TooLong(edge3, "Edge 3");
	}
}

//print info
void Triangle::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << std::setw(36) << std::left << "Edge 1 length" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << edge1 << std::endl;
	std::cout << std::setw(36) << std::left << "Edge 2 length" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << edge2 << std::endl;
	std::cout << std::setw(36) << std::left << "Edge 3 length" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << edge3 << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}

//error class
Triangle::TooLong::TooLong(double _length, std::string _edge) {
	errorMsg = "Error: Given edges can not form a triangle. Edge \"";
	errorMsg.append(_edge);
	errorMsg.append("\" is too long with length ");
	errorMsg.append(std::to_string(_length));
}
Triangle::TooLong::~TooLong(){}
//getters
std::string Triangle::TooLong::getErrorMsg() {
	return errorMsg;
}