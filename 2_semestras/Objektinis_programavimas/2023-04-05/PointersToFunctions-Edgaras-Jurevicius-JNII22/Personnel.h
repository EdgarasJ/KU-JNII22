/*
Author: Edgaras Jurevicius
Date: 2023-03-22
Group: JNII22
Assigment: Eight practical assigment (Pointers To Functions)
Revision date 1: 2023-04-06
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Employee.h"

class Personnel
{
private:
	std::vector<Employee*> employees;
public:
	//constructor and destructor
	Personnel();
	~Personnel();
	//add, remove methods
	void addEmployee(Employee*);
	void removeEmployee(Employee*);
	// filter functions
	void filterYoung();
	void filterMiddleAge();
	void filterOld();
	void filterVeryOld();
	void filterAge();
	void filterExperience();
	void filterSalary();
	//print 
	void printFiltered(void (Personnel::*)(void));
	//main filter
	void filterByCategories();
	void filterInRange();
};

