/*
Author: Edgaras Jurevicius
Date: 2023-03-02
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1: 2023-03-15
*/

#pragma once
#include <iomanip>
#include <iostream>

template <typename T1, typename T2, typename T3>
class Rectangle
{
private:
	T1 length;
	T2 width;
	T3 area;
	//helper
	void calculateArea();
public:
	//constructors and destructor
	Rectangle();
	Rectangle(T1, T2);
	~Rectangle();
	//setters
	void setLength(T1);
	void setWidth(T2);
	//getters
	T1 getLength();
	T2 getWidth();
	T3 getArea();
	//print
	void printInfo();
};

//constructors and destructor
template <typename T1, typename T2, typename T3>
Rectangle<T1, T2, T3>::Rectangle() {
	length = 1.0;
	width = 1.0;
	calculateArea();
}

template <typename T1, typename T2, typename T3>
Rectangle<T1, T2, T3>::Rectangle(T1 _length, T2 _width) {
	length = _length;
	width = _width;
	calculateArea();
}
template <typename T1, typename T2, typename T3>
Rectangle<T1, T2, T3>::~Rectangle() {}
//setters
template <typename T1, typename T2, typename T3>
void Rectangle<T1, T2, T3>::setLength(T1 _length) {
	length = _length;
	calculateArea();
}
template <typename T1, typename T2, typename T3>
void Rectangle<T1, T2, T3>::setWidth(T2 _width) {
	width = _width;
	calculateArea();
}
//getters
template <typename T1, typename T2, typename T3>
T1 Rectangle<T1, T2, T3>::getLength() {
	return length;
}
template <typename T1, typename T2, typename T3>
T2 Rectangle<T1, T2, T3>::getWidth() {
	return width;
}
template <typename T1, typename T2, typename T3>
T3 Rectangle<T1, T2, T3>::getArea() {
	calculateArea();
	return area;
}
//print
template <typename T1, typename T2, typename T3>
void Rectangle<T1, T2, T3>::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Rectangle information : " << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Length (" << std::setw(6) << typeid(length).name() << std::setw(0) << ")" << std::setw(2) << ": " << std::setw(0) << length << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Width (" << std::setw(6) << typeid(width).name() << std::setw(0) << ")" << std::setw(2) << ": " << std::setw(0) << width << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Area (" << std::setw(6) << typeid(area).name() << std::setw(0) << ")" << std::setw(2) << ": " << std::setw(0) << area << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//helper
template <typename T1, typename T2, typename T3>
void Rectangle<T1, T2, T3>::calculateArea() {
	area = length * width;
}

