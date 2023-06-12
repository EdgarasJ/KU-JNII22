/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Prekes
{
protected:
	std::string name;
	double price;
	unsigned int amount;
public:
	//constructor and destructor
	Prekes(std::string, double, unsigned int);
	~Prekes();
	//setters
	void setName(std::string);
	void setPrice(double);
	void setAmount(unsigned int);
	//getters
	std::string getName();
	double getPrice();
	unsigned int getAmount();
	//print
	virtual void printInfo();
};

