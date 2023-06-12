/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-22
*/

#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Drink
{
private:
	std::string name;
	double price;
public:
	//constructors and destructor
	Drink();
	Drink(std::string, double);
	~Drink();
	//setters
	void setName(std::string);
	void setPrice(double);
	//getters
	std::string getName();
	double getPrice();
	// print
	void printDrink();
};

