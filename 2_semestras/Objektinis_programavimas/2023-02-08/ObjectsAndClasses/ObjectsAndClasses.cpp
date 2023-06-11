/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1: 2023-02-08
Revision date 2:
*/

#include "Darbuotojas.h"
#include "GiometrineFigura.h"
#include "Studentas.h"

int main()
{
	/*
	* Left from 1st part of assigment
	*
	Darbuotojas employee1;
	employee1.age = 32;
	employee1.workExp = 12;
	employee1.salary = 2578.00;
	*/

	Darbuotojas employee1(32, 12, 2578.00);
	employee1.printFullInfo();

	GiometrineFigura triangle;
	triangle.printInfo();

	GiometrineFigura quadrilateral(4, false);
	quadrilateral.printInfo();

	unsigned int initCredits[] = {6, 6, 3, 3, 6};
	double initScores[] = {10.0, 10.0, 9.3, 7.5, 8.9};

	Studentas student1("Vardenis", "Pavardenis", initCredits, initScores);
	student1.printInfo();
}
