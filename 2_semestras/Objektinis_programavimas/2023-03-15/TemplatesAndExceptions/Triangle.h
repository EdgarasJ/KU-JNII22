/*
Author: Edgaras Jurevicius
Date: 2023-03-08
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1:
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class Triangle
{
private:
	double edge1;
	double edge2;
	double edge3;
	//helper
	void checkErrors();
public:
	//constructors and destructor
	Triangle();
	Triangle(double, double, double);
	~Triangle();
	//setters
	void setEdge1(double);
	void setEdge2(double);
	void setEdge3(double);
	void setEdges(double, double, double);
	//getters
	double getEdge1();
	double getEdge2();
	double getEdge3();
	//print info
	void printInfo();
	// error class
	class TooLong {
	private:
		std::string errorMsg;
	public:
		TooLong(double, std::string);
		~TooLong();
		//getters
		std::string getErrorMsg();
	};
};

