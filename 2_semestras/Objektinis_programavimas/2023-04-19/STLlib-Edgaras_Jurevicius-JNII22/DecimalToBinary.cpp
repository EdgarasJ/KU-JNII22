/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1: 2023-04-19
*/

#include "DecimalToBinary.h"

//constructor destructor;
DecimalToBinary::DecimalToBinary() {
	decimal = 1;
	minus = false;
	convert(decimal);
	printConversion();
}
DecimalToBinary::DecimalToBinary(int _dec) {
	decimal = _dec;
	minus = false;
	convert(decimal);
	printConversion();
}
DecimalToBinary::~DecimalToBinary(){}
// converter
void DecimalToBinary::convert(int _dec) {
	if (_dec == 0) {
		binStack.push(0);
	}
	if (_dec < 0) {
		minus = true;
		_dec *= -1;
	}
	int bit = 0;
	while (_dec != 0){
		bit = _dec % 2;
		binStack.push(bit);
		_dec = _dec / 2;
	}
}
//print
void DecimalToBinary::printConversion() {
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	std::cout << "Decimal number " << decimal << " in binary: ";
	if (minus) {
		std::cout << "-";
	}
	/*
	for (int i = 0; i < binStack.size(); i++) {
		std::cout << binStack.top();
		binStack.pop();
	}
	*/
	while (!binStack.empty()) {
		std::cout << binStack.top();
		binStack.pop();
	}
	std::cout << std::endl;
	std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
}