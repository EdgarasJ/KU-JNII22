/*
Author: Edgaras Jurevicius
Date: 2023-03-22
Group: JNII22
Assigment: Eight practical assigment (Pointers To Functions)
Revision date 1: 2023-04-06
*/

#include "Personnel.h"

//constructor and destructor
Personnel::Personnel(){
	employees = {};
}
Personnel::~Personnel(){
	for (int i = employees.size() - 1; i >= 0; i--) {
		delete employees[i];
	}
}
//add, remove methods
void Personnel::addEmployee(Employee* _empl){
	employees.push_back(_empl);
}
void Personnel::removeEmployee(Employee* _empl){
	std::vector<Employee*>::iterator it;
	it = std::find(employees.begin(), employees.end(), _empl);
	if (it != employees.end()) {
		employees.erase(it);
	}
}
// filter functions
void Personnel::filterYoung(){
	bool empty = true;
	std::cout << "Young [18-30] employees: " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getAge() > 17 && employees[i]->getAge() < 31) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no Young [18-30] employees in personnel." << std::endl;
	}
}
void Personnel::filterMiddleAge(){
	bool empty = true;
	std::cout << "Middle Age [31-50] employees: " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getAge() > 30 && employees[i]->getAge() < 51) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no Middle Age [18-30] employees in personnel." << std::endl;
	}
}
void Personnel::filterOld(){
	bool empty = true;
	std::cout << "Old [51-70] employees: " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getAge() > 50 && employees[i]->getAge() < 71) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no Old [51-70] employees in personnel." << std::endl;
	}
}
void Personnel::filterVeryOld(){
	bool empty = true;
	std::cout << "Very Old [71 or more] employees: " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getAge() > 70) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no Very Old [71 or more] employees in personnel." << std::endl;
	}
}
void Personnel::filterAge(){
	unsigned int min, max;
	std::cout << "Enter minimum age value:";
	std::cin >> min;
	std::cout << "Enter maximum age value:";
	std::cin >> max;

	bool empty = true;
	std::cout << "Employees with ages beetween " << min << " and " << max << ": " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getAge() >= min && employees[i]->getAge() <= max) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no employees with ages beetween " << min << " and " << max << ": " << std::endl;
	}
}
void Personnel::filterExperience(){
	unsigned int min, max;
	std::cout << "Enter minimum experience value:";
	std::cin >> min;
	std::cout << "Enter maximum experience value:";
	std::cin >> max;

	bool empty = true;
	std::cout << "Employees with experience beetween " << min << " and " << max << ": " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getExperience() >= min && employees[i]->getExperience() <= max) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no employees with experience beetween " << min << " and " << max << ": " << std::endl;
	}
}
void Personnel::filterSalary(){
	double min, max;
	std::cout << "Enter minimum salary value:";
	std::cin >> min;
	std::cout << "Enter maximum salary value:";
	std::cin >> max;

	bool empty = true;
	std::cout << "Employees with salary beetween " << min << " and " << max << ": " << std::endl;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getSalary() >= min && employees[i]->getSalary() <= max) {
			employees[i]->printFullInfoStatic();
			empty = false;
		}
	}
	if (empty) {
		std::cout << "There are no employees with salary beetween " << min << " and " << max << ": " << std::endl;
	}
}
//print 
void Personnel::printFiltered(void (Personnel::*_ptr)(void)){
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	(this->*_ptr)();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//main filter
void Personnel::filterByCategories(){
	bool endLoop = false;
	char ch;
	while (!endLoop) {
		std::cout << "Select age category to filter by:" << std::endl;
		std::cout << "1. Young [18-30]" << std::endl;
		std::cout << "2. Middle Age [31-50]" << std::endl;
		std::cout << "3. Old [51 - 70]" << std::endl;
		std::cout << "4. Very Old [71 or more]" << std::endl;
		std::cout << "0. Exit selection" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case '0':
			endLoop = true;
			break;
		case '1':
			printFiltered(&Personnel::filterYoung);
			break;
		case '2':
			printFiltered(&Personnel::filterMiddleAge);
			break;
		case '3':
			printFiltered(&Personnel::filterOld);
			break;
		case '4':
			printFiltered(&Personnel::filterVeryOld);
			break;
		default:
			break;
		}
	}
}
void Personnel::filterInRange(){
	bool endLoop = false;
	char ch;
	while (!endLoop) {
		std::cout << "Select category to filter with range:" << std::endl;
		std::cout << "1. Age" << std::endl;
		std::cout << "2. Experience" << std::endl;
		std::cout << "3. Salary" << std::endl;
		std::cout << "0. Exit selection" << std::endl;
		std::cin >> ch;
		switch (ch)
		{
		case '0':
			endLoop = true;
			break;
		case '1':
			printFiltered(&Personnel::filterAge);
			break;
		case '2':
			printFiltered(&Personnel::filterExperience);
			break;
		case '3':
			printFiltered(&Personnel::filterSalary);
			break;
		default:
			break;
		}
	}
}