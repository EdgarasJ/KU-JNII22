/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <iomanip>
#include <stack>

class DecimalToBinary
{
private:
	std::stack<int> binStack;
	int decimal;
	bool minus;
public:
	//constructor destructor;
	DecimalToBinary();
	DecimalToBinary(int);
	~DecimalToBinary();
	// converter
	void convert(int);
	//print
	void printConversion();
};

