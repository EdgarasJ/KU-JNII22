/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1: 2023-02-08
Revision date 2: 
*/


#include "Studentas.h"

// constructors, destructor
Studentas::Studentas(std::string _firstname, std::string _lastname, unsigned int _credits[], double _scores[]) {
	firstname = _firstname;
	lastname = _lastname;
	int arrayLength = sizeof(credits) / sizeof(unsigned int);
	for (int i = 0; i < arrayLength; i++) {
		credits[i] = _credits[i];
		scores[i] = _scores[i];
	}
}

Studentas::~Studentas(){}

// setters
void Studentas::setFistname(std::string _firstname) {
	firstname = _firstname;
}

void Studentas::setLastname(std::string _lastname) {
	lastname = _lastname;
}

void Studentas::setCreditsByArray(unsigned int _credits[]) {
	int arrayLength = sizeof(credits) / sizeof(unsigned int);
	for (int i = 0; i < arrayLength; i++) {
		credits[i] = _credits[i];
	}
}

void Studentas::setCreditsByElements(unsigned int el0, unsigned int el1, unsigned int el2, unsigned int el3, unsigned int el4) {
	credits[0] = el0;
	credits[1] = el1;
	credits[2] = el2;
	credits[3] = el3;
	credits[4] = el4;
}

void Studentas::setScoresByArray(double _scores[]) {
	int arrayLength = sizeof(scores) / sizeof(double);
	for (int i = 0; i < arrayLength; i++) {
		scores[i] = _scores[i];
	}
}

void Studentas::setScoresByElements(double el0, double el1, double el2, double el3, double el4) {
	scores[0] = el0;
	scores[1] = el1;
	scores[2] = el2;
	scores[3] = el3;
	scores[4] = el4;
}

// getters
std::string Studentas::getFirstname() {
	return firstname;
}

std::string Studentas::getLastname() {
	return lastname;
}

unsigned int* Studentas::getCredits() {
	return credits;
}

double* Studentas::getScores() {
	return scores;
}

double Studentas::getAverageScore() {
	unsigned int sumOfCredits = 0;
	double sumOfCreditScore = 0;
	int arrayLength = sizeof(scores) / sizeof(double);
	for (int i = 0; i < arrayLength; i++) {
		sumOfCredits += credits[i];
		sumOfCreditScore += credits[i] * scores[i];
	}
	return sumOfCreditScore / sumOfCredits;
}

//print info
void Studentas::printInfo() {
	int arrayLength = sizeof(scores) / sizeof(double);
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
	std::cout << "Studento informacija :" << std::endl;
	std::cout << std::setw(22) << "Vardas" << std::setw(0) << ": " << firstname << std::endl;
	std::cout << std::setw(22) << "Pavarde" << std::setw(0) << ": " << lastname << std::endl;
	std::cout << std::setw(22) << "Kreditai" << std::setw(0) << ": ";
	for (int i = 0; i < arrayLength; i++) {
		std::cout << std::setw(8) << credits[i];
	}
	std::cout << std::endl;
	std::cout << std::setw(22) << "Ivertinimai" << std::setw(0) << ": ";
	for (int i = 0; i < arrayLength; i++) {
		std::cout << std::setw(8) << std::fixed << std::setprecision(3) << scores[i];
	}
	std::cout << std::endl;
	std::cout << std::setw(22) << "Ivertinimu vidurkis" << std::setw(0) << ": " << std::fixed << std::setprecision(3) << Studentas::getAverageScore() << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setfill(' ') << std::setw(0) << std::endl;
}