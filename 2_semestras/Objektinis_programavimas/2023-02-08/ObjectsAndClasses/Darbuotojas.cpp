/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1:
*/


#include "Darbuotojas.h"

// constructors

Darbuotojas::Darbuotojas(unsigned int _age, unsigned int _workExp, double _salary) {
	age = _age;
	workExp = _workExp;
	salary = _salary;
}

// destructor

Darbuotojas::~Darbuotojas() {}

// setters
void Darbuotojas::setAge(unsigned int _age) {
	age = _age;
}

void Darbuotojas::setWorkExp(unsigned int _workExp) {
	workExp = _workExp;
}

void Darbuotojas::setSalary(double _salary) {
	salary = _salary;
}

// getters
unsigned int Darbuotojas::getAge() {
	return age;
}

unsigned int Darbuotojas::getWorkExp() {
	return workExp;
}

double Darbuotojas::getSalary() {
	return salary;
}

double Darbuotojas::getSodraTaxes() {
	return salary * 0.09;
}
double Darbuotojas::getIncomeTaxes() {
	return salary * 0.15;
}

// information output methods
void Darbuotojas::printTaxes() {
	std::cout << std::setw(36) << std::left << "Pajamu mokestis" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << Darbuotojas::getIncomeTaxes() << std::endl;
	std::cout << std::setw(36) << std::left << "Sodros mokestis" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << Darbuotojas::getSodraTaxes() << std::endl;
}

void Darbuotojas::printInfo() {
	std::cout << std::setw(36) << std::left << "Darbuotojo amzius" << std::setw(0) << ": " << age << std::endl;
	std::cout << std::setw(36) << std::left << "Darbuotojo darbo patirtis (metais)" << std::setw(0) << ": " << workExp << std::endl;
	std::cout << std::setw(36) << std::left << "Darbuotojo atlyginimas" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << salary << std::endl;
}

void Darbuotojas::printFullInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
	Darbuotojas::printInfo();
	Darbuotojas::printTaxes();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
}