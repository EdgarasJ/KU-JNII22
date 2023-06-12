/*
Author: Edgaras Jurevicius
Date: 2023-03-22
Group: JNII22
Assigment: Eight practical assigment (Pointers To Functions)
Revision date 1: 2023-04-06
*/

#include "Employee.h"

//constructors and destructor
Employee::Employee() {
	name = "Vardenis";
	surname = "Pavardenis";
	profession = "Lecturer";
	age = 34;
	experience = 10;
	salary = 1500.00;
}
Employee::Employee(std::string _name, std::string _surname, std::string _profession, unsigned int _age, unsigned int _experience, double _salary) {
	name = _name;
	surname = _surname;
	profession = _profession;
	age = _age;
	experience = _experience;
	salary = _salary;
}
Employee::~Employee(){}
//setters
void Employee::setName(std::string _name) {
	name = _name;
}
void Employee::setSurname(std::string _surname) {
	surname = _surname;
}
void Employee::setProfession(std::string _profession) {
	profession = _profession;
}
void Employee::setAge(unsigned int _age) {
	age = _age;
}
void Employee::setExperience(unsigned int _experience) {
	experience = _experience;
}
void Employee::setSalary(double _salary) {
	salary = _salary;
}
//getters
std::string Employee::getName() {
	return name;
}
std::string Employee::getSurname() {
	return surname;
}
std::string Employee::getProfession() {
	return profession;
}
unsigned int Employee::getAge() {
	return age;
}
unsigned int Employee::getExperience() {
	return experience;
}
double Employee::getSalary() {
	return salary;
}
//print info
void Employee::printName() {
	std::cout << std::setw(15) << "Name" << std::setw(3) << ": " << name << std::endl;
}
void Employee::printSurname() {
	std::cout << std::setw(15) << "Surname" << std::setw(3) << ": " << surname << std::endl;
}
void Employee::printProfession() {
	std::cout << std::setw(15) << "Profession" << std::setw(3) << ": " << profession << std::endl;
}
void Employee::printAge() {
	std::cout << std::setw(15) << "Age" << std::setw(3) << ": " << age << std::endl;
}
void Employee::printExperience() {
	std::cout << std::setw(15) << "Experience" << std::setw(3) << ": " << experience << std::endl;
}
void Employee::printSalary() {
	std::cout << std::setw(15) << "Salary" << std::setw(3) << ": " << std::fixed << std::setprecision(2) << salary << std::endl;
}
void Employee::printFullInfo(void (Employee::* pt1)(), void (Employee::*pt2)(), void (Employee::*pt3)(), void (Employee::*pt4)(), void (Employee::*pt5)(), void (Employee::*pt6)()) {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Employee information :" << std::endl;
	(this->*pt1)();
	(this->*pt2)();
	(this->*pt3)();
	(this->*pt4)();
	(this->*pt5)();
	(this->*pt6)();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
void Employee::printFullInfoStatic() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Employee information :" << std::endl;
	printName();
	printSurname();
	printProfession();
	printAge();
	printExperience();
	printSalary();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
//inputs
void Employee::inputName() {
	std::cout << "Please, input employee name: ";
	std::cin >> name;
}
void Employee::inputSurname() {
	std::cout << "Please, input employee surname: ";
	std::cin >> surname;
}
void Employee::inputProfession() {
	std::cout << "Please, input employee profession: ";
	std::cin >> profession;
}
void Employee::inputAge() {
	std::cout << "Please, input employee age: ";
	std::cin >> age;
}
void Employee::inputExperience() {
	std::cout << "Please, input employee experience: ";
	std::cin >> experience;
}
void Employee::inputSalary() {
	std::cout << "Please, input employee salary: ";
	std::cin >> salary;
}
void Employee::inputAll(void (Employee::*pt1)(void), void (Employee::*pt2)(void), void (Employee::*pt3)(void), void (Employee::*pt4)(void), void (Employee::*pt5)(void), void (Employee::*pt6)(void)) {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	//std::cout << "Employee information input :" << std::endl;
	//std::cout << "Pointer inside Method: " << pt1 << std::endl;
	//std::cout << "Type in method: " << typeid(pt1).name() << std::endl;

	(this->*pt1)();
	(this->*pt2)();
	(this->*pt3)();
	(this->*pt4)();
	(this->*pt5)();
	(this->*pt6)();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
void Employee::chooseSequenceOrder(std::string _str) {
	if (_str != "in" && _str != "out") {
		return;
	}
	std::cout << "Please choose next element of Employee info to put in queue sequance : " << std::endl;
	std::vector<std::string> choices = {"Name", "Surname", "Profession", "Age", "Experience", "Salary"};
	std::vector<std::string> sequance = {};

	void (Employee::*functionPointersInput[6])(void) = { &Employee::inputName, &Employee::inputSurname, &Employee::inputProfession, &Employee::inputAge, &Employee::inputExperience, &Employee::inputSalary };
	void (Employee::*functionPointersOutput[6])(void) = { &Employee::printName, &Employee::printSurname, &Employee::printProfession, &Employee::printAge, &Employee::printExperience, &Employee::printSalary };
	int selectedIndexes[6] = {};

	char ch;

	for (int i = 0; i < 6; i++) {
		std::cout << "Current sequance : ";
		for (int k = 0; k < sequance.size(); k++) {
			std::cout << sequance[k] << " ";
		}
		std::cout << std::endl;
		for (int j = 1; j <= choices.size(); j++) {
			
			std::cout << j << ". " << choices[j - 1] << std::endl;
		}
		std::cin >> ch;
		if (ch != '1' && ch != '2' && ch != '3' && ch != '4' && ch != '5' && ch != '6') { continue; }
		sequance.push_back(choices[int(ch - '0') - 1]);
		if (choices[int(ch - '0') - 1] == "Name") {
			selectedIndexes[i] = 0;
		}
		if (choices[int(ch - '0') - 1] == "Surname") {
			selectedIndexes[i] = 1;
		}
		if (choices[int(ch - '0') - 1] == "Profession") {
			selectedIndexes[i] = 2;
		}
		if (choices[int(ch - '0') - 1] == "Age") {
			selectedIndexes[i] = 3;
		}
		if (choices[int(ch - '0') - 1] == "Experience") {
			selectedIndexes[i] = 4;
		}
		if (choices[int(ch - '0') - 1] == "Salary") {
			selectedIndexes[i] = 5;
		}
		choices.erase(choices.begin() + int(ch - '0') - 1);
	}
	if (_str == "in") {
		//std::cout << "Pointer from array: " << functionPointersInput[selectedIndexes[0]] << std::endl;
		//std::cout << "Type in array: " << typeid(functionPointersInput[selectedIndexes[0]]).name() << std::endl;
		//std::cout << "Pointer from array real: " << functionPointersInput[1] << std::endl;
		//std::cout << "Type in array real: " << typeid(functionPointersInput[1]).name() << std::endl;
		//functionPointersInput[selectedIndexes[0]]();
		inputAll(functionPointersInput[selectedIndexes[0]], functionPointersInput[selectedIndexes[1]], functionPointersInput[selectedIndexes[2]], functionPointersInput[selectedIndexes[3]], functionPointersInput[selectedIndexes[4]], functionPointersInput[selectedIndexes[5]]);
	}
	if (_str == "out") {
		printFullInfo(functionPointersOutput[selectedIndexes[0]], functionPointersOutput[selectedIndexes[1]], functionPointersOutput[selectedIndexes[2]], functionPointersOutput[selectedIndexes[3]], functionPointersOutput[selectedIndexes[4]], functionPointersOutput[selectedIndexes[5]]);
	}

}