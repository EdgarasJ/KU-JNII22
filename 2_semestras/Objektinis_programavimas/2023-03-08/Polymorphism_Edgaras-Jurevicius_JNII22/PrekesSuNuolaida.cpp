/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#include "PrekesSuNuolaida.h"

//constructor and destructor
PrekesSuNuolaida::PrekesSuNuolaida(std::string _name, double _price, unsigned int _amount, double _discount) : Prekes(_name, _price, _amount) {
	discount = _discount;
}
PrekesSuNuolaida::~PrekesSuNuolaida(){}
//setters
void PrekesSuNuolaida::setDiscount(double _discount) {
	discount = _discount;
}
//getters
double PrekesSuNuolaida::getDiscount() {
	return discount;
}
//print
void PrekesSuNuolaida::printInfo() {
	std::cout << std::setw(0) << "Product name: " << std::setw(20) << name << std::setw(0) << " Product price (1 pcs):" << std::setw(6) << std::fixed << std::setprecision(2) << price << std::setw(0) << " Amount:" << std::setw(5) << amount << std::setw(0) << " Discount(%): " << discount << " Total price: " << amount * price * (1.00 - discount / 100.00) << std::endl;
}