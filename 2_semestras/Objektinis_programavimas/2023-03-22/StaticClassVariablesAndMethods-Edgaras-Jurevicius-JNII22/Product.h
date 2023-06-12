/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
Revision date 2: 2023-03-30
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <limits>

class Product
{
private:
	std::string name;
	unsigned int amount;
	double unitPrice;
	double totalProductPrice;
	static double totalCartPrice;
	static std::string cheapestName;
	static unsigned int cheapestAmount;
	static double cheapestUnitPrice;
	static double cheapestTotalProductPrice;
	static std::string mostExpensiveName;
	static unsigned int mostExpensiveAmount;
	static double mostExpensiveUnitPrice;
	static double mostExpensiveTotalProductPrice;
	static double discount;
public:
	//constructors and destructor
	Product();
	Product(std::string, unsigned int, double);
	~Product();
	//setters
	void setName(std::string);
	void setAmount(unsigned int);
	void setUnitPrice(double);
	void useDiscount(double);
	// getters
	std::string getName();
	unsigned int getAmount();
	double getUnitPrice();
	double getTotalProductPrice();
	double getTotalCartPrice();
	// print info
	void printInfo();
	void printCheapest();
	void printMostExpensive();
};

