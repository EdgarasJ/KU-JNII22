/*
Author: Edgaras Jurevicius
Date: 2023-03-08
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1:
*/

#include "EmployeeManyErrClasses.h"

//constructors and destructor
EmployeeManyErrClasses::EmployeeManyErrClasses() {
	age = 19;
	experience = 1.0;
	salary = 600.0;
	checkErrors();
}
EmployeeManyErrClasses::EmployeeManyErrClasses(unsigned int _age, double _exp, double _salary) {
	age = _age;
	experience = _exp;
	salary = _salary;
	checkErrors();
}
EmployeeManyErrClasses::~EmployeeManyErrClasses(){}
//setters
void EmployeeManyErrClasses::setAge(unsigned int _age) {
	age = _age;
	checkErrors();
}
void EmployeeManyErrClasses::setExp(double _exp) {
	experience = _exp;
	checkErrors();
}
void EmployeeManyErrClasses::setSalary(double _salary) {
	salary = _salary;
	checkErrors();
}
//getters
unsigned int EmployeeManyErrClasses::getAge() {
	return age;
}
double EmployeeManyErrClasses::getExp() {
	return experience;
}
double EmployeeManyErrClasses::getSalary() {
	return salary;
}
//print info;
void EmployeeManyErrClasses::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << std::setw(36) << std::left << "Employee age" << std::setw(0) << ": " << age << std::endl;
	std::cout << std::setw(36) << std::left << "Employee work experience" << std::setw(0) << ": " << experience << std::endl;
	std::cout << std::setw(36) << std::left << "Employee salary" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << salary << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
// helper
void EmployeeManyErrClasses::checkErrors() {
	if (age < 18 || age > 70) {
		throw ErrAge(age);
	}
	if (experience > age - 18){
		throw ErrExp(experience, age);
	}
	if (salary < 500.0) {
		throw ErrSalary(salary);
	}
}
// error classes
EmployeeManyErrClasses::ErrAge::ErrAge(unsigned int _age) {
	errMsg = "Error: Employee age should be in interval [18, 70]. Current value: ";
	errMsg.append(std::to_string(_age));
}
EmployeeManyErrClasses::ErrAge::~ErrAge(){}
std::string EmployeeManyErrClasses::ErrAge::getErrMsg() {
	return errMsg;
}
EmployeeManyErrClasses::ErrExp::ErrExp(double _exp, unsigned int _age) {
	errMsg = "Error: Employee work experience can not be more than ";
	errMsg.append(std::to_string(_age - 18));
	errMsg.append(". Current value: ");
	errMsg.append(std::to_string(_exp));
}
EmployeeManyErrClasses::ErrExp::~ErrExp() {}
std::string EmployeeManyErrClasses::ErrExp::getErrMsg() {
	return errMsg;
}
EmployeeManyErrClasses::ErrSalary::ErrSalary(double _salary) {
	errMsg = "Error: Employee salary can not be lower than 500. Current value: ";
	errMsg.append(std::to_string(_salary));
}
EmployeeManyErrClasses::ErrSalary::~ErrSalary(){}
std::string EmployeeManyErrClasses::ErrSalary::getErrMsg() {
	return errMsg;
}