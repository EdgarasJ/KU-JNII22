/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#include "Studentas.h"

//constructors and destructors
Studentas::Studentas() : Asmuo() {
	id = "KU20231234";
	subjects = {"Algebra", "Object Oriented Programming", "Algorythms and Data Structures", "Logic", "Physics"};
	averageScore = 9.8f;
}
Studentas::Studentas(std::string _id, std::vector<std::string> _subjects, float _avgScore) : Asmuo() {
	id = _id;
	subjects = _subjects;
	averageScore = _avgScore;
}
Studentas::Studentas(std::string _name, std::string _surname, unsigned short int _age, std::string _id, std::vector<std::string> _subjects, float _avgScore) : Asmuo(_name, _surname, _age) {
	id = _id;
	subjects = _subjects;
	averageScore = _avgScore;
}
Studentas::~Studentas(){}
//setters
void Studentas::setId(std::string _id) {
	id = _id;
}
void Studentas::setSubjects(std::vector<std::string> _subjects) {
	subjects = _subjects;
}
void Studentas::setAverageScore(float _avgScore) {
	averageScore = _avgScore;
}
//getters
std::string Studentas::getId() {
	return id;
}
std::vector<std::string> Studentas::getSubjects() {
	return subjects;
}
float Studentas::getAverageScore() {
	return averageScore;
}
//print info
void Studentas::printInfo() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Student's information : " << std::endl;
	printInBlock();
	std::cout << std::setw(10) << " " << std::setw(20) << "ID" << std::setw(2) << ": " << std::setw(0) << id << std::endl;
	std::cout << std::setw(10) << " " << std::setw(20) << "Subjects" << std::setw(2) << ": " << std::setw(0) << std::endl;
	for (int i = 0; i < subjects.size(); i++) {
		std::cout << std::setw(40) << " " << subjects[i] << std::endl;
	}
	std::cout << std::setw(10) << " " << std::setw(20) << "Average Score" << std::setw(2) << ": " << std::setw(0) << averageScore << std::endl;

	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}