/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1:
*/

#pragma once
#include "Drink.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

class CoffeeMachine
{
private:
	static Drink* drinks[5];
	static double totalPrice;
	static double amountPaid;
	static double leftToPay;
	static std::vector<Drink*> selectedDrinks;
public:
	// constructor and destructor
	CoffeeMachine();
	~CoffeeMachine();
	// output
	static void printSelection();
	static void returnChange();
	// input
	static void chooseDrinks();
	static void pay();
};

