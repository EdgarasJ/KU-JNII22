/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-04
Revision date 2: 2023-02-09
*/

#pragma once
#include <iostream>
#include "Atlyginimas.h"
#include <iomanip>

class Darbuotojas
{
public:
	// constructors and destructor
	Darbuotojas();
	Darbuotojas(unsigned int, unsigned int, Atlyginimas);
	Darbuotojas(unsigned int, unsigned int, double);
	~Darbuotojas();
	// setters
	void setAge(unsigned int);
	void setWorkExp(unsigned int);
	void setSalary(double);
	// getters
	unsigned int getAge();
	unsigned int getWorkExp();
	double getSalaryBeforeTaxes();
	double getEmployerTaxes();
	double getIncomeTaxes();
	double getSocialTaxes();
	double getSalaryAfterTaxes();
	// print info
	void printInfo();
private:
	unsigned int age;
	unsigned int workExp;
	Atlyginimas salary;
};

