/*
Author: Edgaras Jurevicius
Date: 2023-03-08
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1:
*/

#include "EmployeeOneErrClass.h"

//constructors and destructor
EmployeeOneErrClass::EmployeeOneErrClass() {
	age = 19;
	experience = 1.0;
	salary = 600.0;
	checkErrors();
}
EmployeeOneErrClass::EmployeeOneErrClass(unsigned int _age, double _exp, double _salary) {
	age = _age;
	experience = _exp;
	salary = _salary;
	checkErrors();
}
EmployeeOneErrClass::~EmployeeOneErrClass() {}
//setters
void EmployeeOneErrClass::setAge(unsigned int _age) {
	age = _age;
	checkErrors();
}
void EmployeeOneErrClass::setExp(double _exp) {
	experience = _exp;
	checkErrors();
}
void EmployeeOneErrClass::setSalary(double _salary) {
	salary = _salary;
	checkErrors();
}
//getters
unsigned int EmployeeOneErrClass::getAge() {
	return age;
}
double EmployeeOneErrClass::getExp() {
	return experience;
}
double EmployeeOneErrClass::getSalary() {
	return salary;
}
//print info;
void EmployeeOneErrClass::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << std::setw(36) << std::left << "Employee age" << std::setw(0) << ": " << age << std::endl;
	std::cout << std::setw(36) << std::left << "Employee work experience" << std::setw(0) << ": " << experience << std::endl;
	std::cout << std::setw(36) << std::left << "Employee salary" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << salary << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
// helper
void EmployeeOneErrClass::checkErrors() {
	std::string msg = "";
	bool throwError = false;
	if (age < 18 || age > 70) {
		throwError = true;
		msg.append("Error: Employee age should be in interval [18, 70]. Current value: ");
		msg.append(std::to_string(age));
		msg.append("\n");
	}
	if (experience > age - 18) {
		throwError = true;
		msg.append("Error: Employee work experience can not be more than ");
		msg.append(std::to_string(age - 18));
		msg.append(". Current value: ");
		msg.append(std::to_string(experience));
		msg.append("\n");
	}
	if (salary < 500.0) {
		throwError = true;
		msg.append("Error: Employee salary can not be lower than 500. Current value: ");
		msg.append(std::to_string(salary));
		msg.append("\n");
	}
	if (throwError) {
		throw ErrorEmpl(msg);
	}
}
// error classes
EmployeeOneErrClass::ErrorEmpl::ErrorEmpl(std::string _msg) {
	errMsg = _msg;
}
EmployeeOneErrClass::ErrorEmpl::~ErrorEmpl() {}
std::string EmployeeOneErrClass::ErrorEmpl::getErrMsg() {
	return errMsg;
}