/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

class Darbuotojas
{
/*
* Left from 1st part of assigment
* 
public:
	unsigned int age;
	unsigned int workExp;
	unsigned int salary;
*/
public:
	// constructors, destructor
	Darbuotojas(unsigned int, unsigned int, double);
	~Darbuotojas();
	// getters
	unsigned int getAge();
	unsigned int getWorkExp();
	double getSalary();
	double getSodraTaxes();
	double getIncomeTaxes();
	// setters
	void setAge(unsigned int);
	void setWorkExp(unsigned int);
	void setSalary(double);
	// information output methods
	void printTaxes();
	void printInfo();
	void printFullInfo();
private:
	unsigned int age;
	unsigned int workExp;
	double salary;
};

