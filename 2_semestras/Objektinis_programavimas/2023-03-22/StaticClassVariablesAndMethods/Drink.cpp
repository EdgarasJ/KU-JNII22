/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-22
*/

#include "Drink.h"

//constructors and destructor
Drink::Drink() {
	name = "Black Coffee";
	price = 1.50;
}
Drink::Drink(std::string _name, double _price) {
	name = _name;
	price = _price;
}
Drink::~Drink(){}
//setters
void Drink::setName(std::string _name) {
	name = _name;
}
void Drink::setPrice(double _price) {
	price = _price;
}
//getters
std::string Drink::getName() {
	return name;
}
double Drink::getPrice() {
	return price;
}
// print
void Drink::printDrink() {
	std::cout << std::setw(20) << name << std::setw(6) << std::setfill(' ') << " " << std::setw(0) << "Price: " << std::fixed << std::setprecision(2) << std::setw(5) << price << std::endl;
}