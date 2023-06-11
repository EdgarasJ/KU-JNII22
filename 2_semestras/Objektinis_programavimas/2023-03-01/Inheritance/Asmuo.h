/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Asmuo
{
protected:
	std::string name;
	std::string surname;
	unsigned short int age;
public:
	//constructors and destructor
	Asmuo();
	Asmuo(std::string, std::string, unsigned short int);
	~Asmuo();
	//setters
	void setName(std::string);
	void setSurname(std::string);
	void setAge(unsigned short int);
	//getters
	std::string getName();
	std::string getSurname();
	unsigned short int getAge();
	//print info
	void printInBlock();
	void printFull();
};

