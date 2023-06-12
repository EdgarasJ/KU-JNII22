/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include "Funkcija.h"
#include <iostream>
#include <iomanip>

class TiesineFunkcija :
    public Funkcija
{
protected:
	double k;
	double b;
	void setFx();
public:
	//constructors and destructor
	TiesineFunkcija();
	TiesineFunkcija(double, double);
	TiesineFunkcija(double, double, double);
	~TiesineFunkcija();
	// setters
	void setX(double);
	void setK(double);
	void setB(double);
	// getters
	double getK();
	double getB();
	void getFx();
};

