/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include "Funkcija.h"
#include <cmath>
#include <iostream>
#include <iomanip>

class LaipsnineFunkcija :
    public Funkcija
{
protected:
	double n;
	void setFx();	
public:
	//constructors and destructor
	LaipsnineFunkcija();
	LaipsnineFunkcija(double);
	LaipsnineFunkcija(double, double);
	~LaipsnineFunkcija();
	// setters
	void setX(double);
	void setN(double);
	// getters
	double getN();
	void getFx();
};

