/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include "Prekes.h"
#include <iostream>
#include <iomanip>

class PrekesSuNuolaida :
    public Prekes
{
protected:
	double discount;
public:
	//constructor and destructor
	PrekesSuNuolaida(std::string, double, unsigned int, double);
	~PrekesSuNuolaida();
	//setters
	void setDiscount(double);
	//getters
	double getDiscount();
	//print
	void printInfo();
};

