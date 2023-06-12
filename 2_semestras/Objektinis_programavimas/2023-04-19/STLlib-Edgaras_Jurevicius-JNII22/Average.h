/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1: 2023-04-12
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <deque>
#include <string>

class Average
{
private:
	std::deque<double> averages;
	std::deque<double> numbers;
public:
	// constructor and destructor
	Average();
	~Average();
	// input
	void inputNumbers();
	// output
	void printResult();
	// calculate averages
	void calculateResult();
};

