/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1:
*/

#include "Asmuo.h"

//constructors and destructor
Asmuo::Asmuo() {
	name = "Vardenis";
	surname = "Pavardenis";
	age = 20;
}
Asmuo::Asmuo(std::string _name, std::string _surname, unsigned short int _age) {
	name = _name;
	surname = _surname;
	age = _age;
}
Asmuo::~Asmuo(){}
//setters
void Asmuo::setName(std::string _name) {
	name = _name;
}
void Asmuo::setSurname(std::string _surname) {
	surname = _surname;
}
void Asmuo::setAge(unsigned short int _age) {
	age = _age;
}
//getters
std::string Asmuo::getName() {
	return name;
}
std::string Asmuo::getSurname() {
	return surname;
}
unsigned short int Asmuo::getAge() {
	return age;
}
//print info
void Asmuo::printInBlock() {
	std::cout << std::setw(10) << " "  << std::setw(20) << "Name" << std::setw(2) << ": " << std::setw(0) << name << std::endl;
	std::cout << std::setw(10) << " "  << std::setw(20) << "Surname" << std::setw(2) << ": " << std::setw(0) << surname << std::endl;
	std::cout << std::setw(10) << " "  << std::setw(20) << "Age" << std::setw(2) << ": " << std::setw(0) << age << std::endl;
}
void Asmuo::printFull() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Person's information : " << std::endl;
	printInBlock();
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}