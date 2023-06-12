/*
Author: Edgaras Jurevicius
Date: 2023-03-22
Group: JNII22
Assigment: Eight practical assigment (Pointers To Functions)
Revision date 1:
*/

#pragma once
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

class Employee
{
private:
	std::string name;
	std::string surname;
	std::string profession;
	unsigned int age;
	unsigned int experience;
	double salary;
public:
	//constructors and destructor
	Employee();
	Employee(std::string, std::string, std::string, unsigned int, unsigned int, double);
	~Employee();
	//setters
	void setName(std::string);
	void setSurname(std::string);
	void setProfession(std::string);
	void setAge(unsigned int);
	void setExperience(unsigned int);
	void setSalary(double);
	//getters
	std::string getName();
	std::string getSurname();
	std::string getProfession();
	unsigned int getAge();
	unsigned int getExperience();
	double getSalary();
	//print info
	void printName();
	void printSurname();
	void printProfession();
	void printAge();
	void printExperience();
	void printSalary();
	void printFullInfo(void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void));
	void printFullInfoStatic();
	//inputs
	void inputName();
	void inputSurname();
	void inputProfession();
	void inputAge();
	void inputExperience();
	void inputSalary();
	void inputAll(void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void), void (Employee::*)(void));
	void chooseSequenceOrder(std::string);
};

