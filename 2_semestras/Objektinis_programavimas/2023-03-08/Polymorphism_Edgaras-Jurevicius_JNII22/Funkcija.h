/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include <iostream>

class Funkcija
{
protected:
	double x;
	double fx;
	void setFx();	
public:
	//constructors and destructor
	Funkcija();
	Funkcija(double);
	virtual ~Funkcija();
	// setters
	void setX(double);
	// getters
	double getX();
	//print
	virtual void getFx();
};

