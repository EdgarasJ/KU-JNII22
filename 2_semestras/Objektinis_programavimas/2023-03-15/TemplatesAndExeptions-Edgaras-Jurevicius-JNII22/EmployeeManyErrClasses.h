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

class EmployeeManyErrClasses
{
private:
	unsigned int age;
	double experience;
	double salary;
	// helper
	void checkErrors();
public:
	//constructors and destructor
	EmployeeManyErrClasses();
	EmployeeManyErrClasses(unsigned int, double, double);
	~EmployeeManyErrClasses();
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
	// error classes
	class ErrAge {
	private:
		std::string errMsg;
	public:
		ErrAge(unsigned int);
		~ErrAge();
		std::string getErrMsg();
	};
	class ErrExp {
	private:
		std::string errMsg;
	public:
		ErrExp(double, unsigned int);
		~ErrExp();
		std::string getErrMsg();
	};
	class ErrSalary {
	private:
		std::string errMsg;
	public:
		ErrSalary(double);
		~ErrSalary();
		std::string getErrMsg();
	};
};

