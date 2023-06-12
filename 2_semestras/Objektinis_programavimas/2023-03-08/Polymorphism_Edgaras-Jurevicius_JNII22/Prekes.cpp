/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "Prekes.h"

//constructor and destructor
Prekes::Prekes(std::string _name, double _price, unsigned int _amount) {
	name = _name;
	price = _price;
	amount = _amount;
}
Prekes::~Prekes(){}
//setters
void Prekes::setName(std::string _name) {
	name = _name;
}
void Prekes::setPrice(double _price) {
	price = _price;
}
void Prekes::setAmount(unsigned int _amount) {
	amount = _amount;
}
//getters
std::string Prekes::getName() {
	return name;
}
double Prekes::getPrice() {
	return price;
}
unsigned int Prekes::getAmount() {
	return amount;
}
//print
void Prekes::printInfo() {
	std::cout << std::setw(0) << "Product name: " << std::setw(20) << name << std::setw(0) << " Product price (1 pcs):" << std::setw(6) << std::fixed << std::setprecision(2) << price << std::setw(0) << " Amount:" << std::setw(5) << amount << std::setw(0) << " Total price: " << amount * price << std::endl;
}