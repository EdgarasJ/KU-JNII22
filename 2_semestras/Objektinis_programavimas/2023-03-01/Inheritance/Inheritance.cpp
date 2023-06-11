/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-03-01
*/

#include <iostream>
#include "Studentas.h"
#include "Vektorius3D.h"
#include "Ritinys.h"
#include "StaciakampisGretasienis.h"

int main()
{
	Asmuo person;
	person.printFull();
	Studentas student;
	student.printInfo();
	Vektorius2D v1;
	v1.printInfo();
	Vektorius3D v2;
	v2.printInfo();
	Ritinys cylinder;
	cylinder.printInfo();
	std::cout << "Figure with default values 0.0: " << std::endl;
	GeometrineFigura fig1;
	fig1.printInfo();
	std::cout << "Figure with custom values 8.0, 3.75: " << std::endl;
	GeometrineFigura fig2(8.0, 3.75);
	fig2.printInfo();
	std::cout << "Rectangle with default values 3.0, 2.0: " << std::endl;
	Staciakampis rect1;
	rect1.printInfo();
	std::cout << "Rectangle with custom values 1.5, 2.5: " << std::endl;
	Staciakampis rect2(1.5, 2.5);
	rect2.printInfo();
	std::cout << "Cuboid with default values 3.0, 2.0, 4.0: " << std::endl;
	StaciakampisGretasienis cuboid1;
	cuboid1.printInfo();
	std::cout << "Cuboid with custom values 2.4, 3.2, 1.5: " << std::endl;
	StaciakampisGretasienis cuboid2(2.4, 3.2, 1.5);
	cuboid2.printInfo();
}

