/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-04
*/

#pragma once

class Atlyginimas
{
public:
	// constructors and destructor
	Atlyginimas(double);
	Atlyginimas();
	~Atlyginimas();
	// setters
	void setSalary(double);
	// getters
	double getSalary();
	double getEmployerTaxes();
	double getSocialTaxes();
	double getIncomeTaxes();
	double getSalaryAfterTaxes();
private:
	double salary;
};

