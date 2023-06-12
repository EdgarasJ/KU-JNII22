/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
Revision date 2: 2023-03-30
*/

#include "Product.h"

double Product::totalCartPrice = 0.0;
std::string Product::cheapestName = "";
unsigned int Product::cheapestAmount = 0;
double Product::cheapestUnitPrice = std::numeric_limits<double>::max();
double Product::cheapestTotalProductPrice = 0.0;
std::string Product::mostExpensiveName = "";
unsigned int Product::mostExpensiveAmount = 0;
double Product::mostExpensiveUnitPrice = std::numeric_limits<double>::min();
double Product::mostExpensiveTotalProductPrice = 0.0;
double Product::discount = 0.0;

//constructors and destructor
Product::Product() {
	name = " ";
	amount = 0;
	unitPrice = 0.0;
	totalProductPrice = amount * unitPrice;
	totalCartPrice += totalProductPrice;
	if (cheapestUnitPrice > unitPrice) {
		cheapestName = name;
		cheapestAmount = amount;
		cheapestUnitPrice = unitPrice;
		cheapestTotalProductPrice = totalProductPrice;
	}
	if (mostExpensiveUnitPrice < unitPrice) {
		mostExpensiveName = name;
		mostExpensiveAmount = amount;
		mostExpensiveUnitPrice = unitPrice;
		mostExpensiveTotalProductPrice = totalProductPrice;
	}
}
Product::Product(std::string _name, unsigned int _amount, double _unitPrice) {
	name = _name;
	amount = _amount;
	unitPrice = _unitPrice;
	totalProductPrice = amount * unitPrice;
	totalCartPrice += totalProductPrice;
	if (cheapestUnitPrice > unitPrice) {
		cheapestName = name;
		cheapestAmount = amount;
		cheapestUnitPrice = unitPrice;
		cheapestTotalProductPrice = totalProductPrice;
	}
	if (mostExpensiveUnitPrice < unitPrice) {
		mostExpensiveName = name;
		mostExpensiveAmount = amount;
		mostExpensiveUnitPrice = unitPrice;
		mostExpensiveTotalProductPrice = totalProductPrice;
	}
}
Product::~Product(){
	totalCartPrice -= totalProductPrice;
}
//setters
void Product::setName(std::string _name) {
	name = _name;
}
void Product::setAmount(unsigned int _amount) {
	totalCartPrice -= totalProductPrice;
	amount = _amount;
	totalProductPrice = amount * unitPrice;
	totalCartPrice += totalProductPrice;
}
void Product::setUnitPrice(double _unitPrice) {
	totalCartPrice -= totalProductPrice;
	unitPrice = _unitPrice;
	totalProductPrice = amount * unitPrice;
	totalCartPrice += totalProductPrice;
}
void Product::useDiscount(double _discount) {
	if (_discount > 100 || _discount < 0.0){
		std::cout << "Error: discount can be a number beetween 0 and 100" << std::endl;
		_discount = 0;
	}
	//totalCartPrice = totalCartPrice * (1.0 - (_discount / 100.00));
	discount = _discount;
}
// getters
std::string Product::getName() {
	return name;
}
unsigned int Product::getAmount() {
	return amount;
}
double Product::getUnitPrice() {
	return unitPrice;
}
double Product::getTotalProductPrice() {
	return totalProductPrice;
}
double Product::getTotalCartPrice() {
	return totalCartPrice;
}
// print info
void Product::printInfo() {
	std::cout << std::setw(0) << "Product name: " << std::setw(20) << name << std::setw(0) << " Product price (1 pcs):" << std::setw(6) << std::fixed << std::setprecision(2) << unitPrice << std::setw(0) << " Amount:" << std::setw(5) << amount << std::setw(0) << " Total price: " << totalProductPrice;
	if (discount > 0) {
		std::cout << " Discount: " << discount << "% Price after discount: " << totalProductPrice * ((100 - discount) / 100);
	}
	std::cout << std::endl;
}
void Product::printCheapest() {
	std::cout << std::setw(0) << "Cheapest product name: " << std::setw(20) << cheapestName << std::setw(0) << " Product price (1 pcs):" << std::setw(6) << std::fixed << std::setprecision(2) << cheapestUnitPrice << std::setw(0) << " Amount:" << std::setw(5) << cheapestAmount << std::setw(0) << " Total price: " << cheapestTotalProductPrice;
	if (discount > 0) {
		std::cout << " Discount: " << discount << "% Price after discount: " << cheapestTotalProductPrice * ((100 - discount) / 100);
	}
	std::cout << std::endl;
}
void Product::printMostExpensive() {
	std::cout << std::setw(0) << "Most expensive product name: " << std::setw(20) << mostExpensiveName << std::setw(0) << " Product price (1 pcs):" << std::setw(6) << std::fixed << std::setprecision(2) << mostExpensiveUnitPrice << std::setw(0) << " Amount:" << std::setw(5) << mostExpensiveAmount << std::setw(0) << " Total price: " << mostExpensiveTotalProductPrice;
	if (discount > 0) {
		std::cout << " Discount: " << discount << "% Price after discount: " << mostExpensiveTotalProductPrice * ((100 - discount) / 100);
	}
	std::cout << std::endl;
}