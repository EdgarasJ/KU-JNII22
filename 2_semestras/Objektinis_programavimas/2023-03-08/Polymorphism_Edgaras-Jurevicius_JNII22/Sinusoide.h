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

class Sinusoide :
    public Funkcija
{
protected:
    void setFx();
public:
	//constructors and destructor
	Sinusoide();
	Sinusoide(double);
	~Sinusoide();
	// getters
	void getFx();
};

