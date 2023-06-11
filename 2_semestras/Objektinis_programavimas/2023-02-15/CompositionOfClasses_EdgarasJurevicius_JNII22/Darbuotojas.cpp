/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-04
Revision date 2: 2023-02-09
*/


#include "Darbuotojas.h"

// constructors and destructor
Darbuotojas::Darbuotojas() {
	age = 0;
	workExp = 0;
	salary.setSalary(0.0);
}
Darbuotojas::Darbuotojas(unsigned int _age, unsigned int _workExp, Atlyginimas _salary) {
	age = _age;
	workExp = _workExp;
	salary.setSalary(_salary.getSalary());
}
Darbuotojas::Darbuotojas(unsigned int _age, unsigned int _workExp, double _salary) {
	age = _age;
	workExp = _workExp;
	salary.setSalary(_salary);
}
Darbuotojas::~Darbuotojas(){}
// setters
void Darbuotojas::setAge(unsigned int _age) {
	age = _age;
}
void Darbuotojas::setWorkExp(unsigned int _workExp) {
	workExp = _workExp;
}
void Darbuotojas::setSalary(double _salary) {
	salary.setSalary(_salary);
}
// getters
unsigned int Darbuotojas::getAge() {
	return age;
}
unsigned int Darbuotojas::getWorkExp() {
	return workExp;
}
double Darbuotojas::getSalaryBeforeTaxes() {
	return salary.getSalary();
}
double Darbuotojas::getEmployerTaxes() {
	return salary.getEmployerTaxes();
}
double Darbuotojas::getIncomeTaxes() {
	return salary.getIncomeTaxes();
}
double Darbuotojas::getSocialTaxes() {
	return salary.getSocialTaxes();
}
double Darbuotojas::getSalaryAfterTaxes() {
	return salary.getSalaryAfterTaxes();
}
// print info
void Darbuotojas::printInfo() {
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
	std::cout << "Employee information :" << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Age" << std::setw(0) << ": " << age << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Work experience (years)" << std::setw(0) << ": " << workExp << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Salary before taxes" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getSalaryBeforeTaxes() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Employer taxes (31.17%)" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getEmployerTaxes() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Salary before employee taxes" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getSalaryBeforeTaxes() - getEmployerTaxes() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Income taxes (15%)" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getIncomeTaxes() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Social taxes (9%)" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getSocialTaxes() << std::endl;
	std::cout << std::left << std::setw(10) << " " << std::setw(30) << "Salary after taxes" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << getSalaryAfterTaxes() << std::endl;
	std::cout << std::setw(50) << std::setfill('=') << "=" << std::endl << std::setw(0) << std::setfill(' ');
}