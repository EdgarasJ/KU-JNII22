/*
Author: Edgaras Jurevicius
Date: 2023-03-08
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1:
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>

class EmployeeOneErrClass
{
private:
	unsigned int age;
	double experience;
	double salary;
	// helper
	void checkErrors();
public:
	//constructors and destructor
	EmployeeOneErrClass();
	EmployeeOneErrClass(unsigned int, double, double);
	~EmployeeOneErrClass();
	//setters
	void setAge(unsigned int);
	void setExp(double);
	void setSalary(double);
	//getters
	unsigned int getAge();
	double getExp();
	double getSalary();
	//print info;
	void printInfo();
	// error class
	class ErrorEmpl {
	private:
		std::string errMsg;
	public:
		ErrorEmpl(std::string);
		~ErrorEmpl();
		std::string getErrMsg();
	};
};

