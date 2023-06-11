/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-04
*/


#include "Atlyginimas.h"

// constructors and destructor
Atlyginimas::Atlyginimas(double _salary) {
	salary = _salary;
}
Atlyginimas::Atlyginimas() {
	salary = 0;
}
Atlyginimas::~Atlyginimas(){}
// setters
void Atlyginimas::setSalary(double _salary) {
	salary = _salary;
}
// getters
double Atlyginimas::getSalary() {
	return salary;
}
double Atlyginimas::getEmployerTaxes() {
	return salary * 0.3117;
}
double Atlyginimas::getSocialTaxes() {
	return (salary - getEmployerTaxes()) * 0.09;
}
double Atlyginimas::getIncomeTaxes() {
	return (salary - getEmployerTaxes()) * 0.15;
}
double Atlyginimas::getSalaryAfterTaxes() {
	return salary - getEmployerTaxes() - getSocialTaxes() - getIncomeTaxes();
}