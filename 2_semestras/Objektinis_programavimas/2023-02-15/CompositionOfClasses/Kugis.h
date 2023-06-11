/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-08
Revision date 2: 2023-02-09
Revision date 3: 2023-02-10
*/

#pragma once
#include "Skritulys.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Atkarpa.h"
#include "Taskas.h"

class Kugis
{
public:
	//constructors and destructor
	Kugis(double, double, double);
	Kugis(Skritulys, Skritulys, double);
	Kugis(double, double, Atkarpa);
	Kugis(double, double, Taskas, Taskas);
	Kugis(double, double, double, double, double, double);
	Kugis(Skritulys, Skritulys, Atkarpa);
	Kugis(Skritulys, Skritulys, Taskas, Taskas);
	Kugis(Skritulys, Skritulys, double, double, double, double);
	~Kugis();
	// setters
	void setAltitude(double);
	void setTopCircle(Skritulys);
	void setTopCircleRadius(double);
	void setBottomCircle(Skritulys);
	void setBottomCircleRadius(double);
	void setCircles(Skritulys, Skritulys);
	void setCirclesRadius(double, double);
	// getters
	double getAltitude();
	Skritulys getTopCircle();
	Skritulys getBottomCircle();
	double getVolume();
	// print info
	void printInfoAltitude();
private:
	Skritulys topCircle;
	Skritulys bottomCircle;
	double altitude;
};

