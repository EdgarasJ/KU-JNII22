/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1: 2023-04-12
Revision date 2: 2023-04-19
*/

#include "Average.h"

// constructor and destructor
Average::Average() {
	inputNumbers();
}
Average::~Average(){}
// input
void Average::inputNumbers() {
	std::string input;
	while (true) {
		std::cout << "Please, insert number or 'quit' to exit:" << std::endl;
		std::cin >> input;
		if (input == "quit") {
			break;
		}
		numbers.push_back(std::stod(input));
		if (numbers.size() > 5) {
			numbers.pop_front();
		}
		calculateResult();
	}
}
// output
void Average::printResult() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Last 5 (if available) numbers Yiu inputed:" << std::endl;
	for (int i = 0; i < numbers.size(); i++) {
		std::cout << numbers.at(i) << "   ";
	}
	std::cout << std::endl;
	std::cout << "Last 4 (if available) averages of numbers You inputed:" << std::endl;
	for (int i = 0; i < averages.size(); i++) {
		std::cout << std::fixed << std::setprecision(3) << averages.at(i) << "   ";
	}
	std::cout << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}
// calculate averages
void Average::calculateResult() {
	double average = 0.0;
	for (int i = 0; i < numbers.size(); i++) {
		average += numbers.at(i);
	}
	average /= numbers.size();
	averages.push_back(average);
	if (averages.size() > 4) {
		averages.pop_front();
	}
	printResult();
}