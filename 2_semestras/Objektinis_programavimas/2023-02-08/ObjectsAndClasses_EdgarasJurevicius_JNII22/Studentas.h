/*
Author: Edgaras Jurevicius
Date: 2023-02-02
Group: JNII22
Assigment: Second practical assigment (Objects and Classes)
Revision date 1:
*/

#pragma once
#include <iostream>
#include <string>
#include <iomanip>

class Studentas
{
public:
	// constructors, destructor
	Studentas(std::string, std::string, unsigned int[], double[]);
	~Studentas();

	// setters
	void setFistname(std::string);
	void setLastname(std::string);
	void setCreditsByArray(unsigned int[]);
	void setCreditsByElements(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
	void setScoresByArray(double[]);
	void setScoresByElements(double, double, double, double, double);

	// getters
	std::string getFirstname();
	std::string getLastname();
	unsigned int * getCredits();
	double * getScores();
	double getAverageScore();

	// info print
	void printInfo();
private:
	std::string firstname;
	std::string lastname;
	unsigned int credits[5];
	double scores[5];
};

