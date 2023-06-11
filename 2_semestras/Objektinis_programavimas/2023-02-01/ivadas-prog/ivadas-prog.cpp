/*
Author: Edgaras Jurevicius
Date: 2023-02-01
Group: JNII22
Assigment: First practical assigment (Ivadas i OP)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

void pow2();
char menu();
void digitSum();
void arrayNoDoubles();
void printVector(vector<int>&);
void arraySort();
void factorial();
void checkPrime();
bool isPrime(int);
int enterInteger(string, string, bool, bool);

int main(){
	bool exit = false;
	char selection;
	// operation selection loop
	while (!exit) {
		selection = menu();
		switch (selection) {
		case '1':
			pow2();
			break;
		case '2':
			digitSum();
			break;
		case '3':
			arrayNoDoubles();
			break;
		case '4':
			arraySort();
			break;
		case '5':
			factorial();
			break;
		case '6':
			checkPrime();
			break;
		case 'q':
			exit = true;
			break;
		default:
			cout << "Error: Wrong selection." << endl;
			break;
		}
	}
	return 0;
}

// operation selection menu
char menu() {
	cout << "=========================================" << endl;
	cout << "Please select an operation or 'q' to quit:" << endl;
	cout << "1. Power of 2 of integers until selected upper bound." << endl;
	cout << "2. Sum of digits." << endl;
	cout << "3. Array without doubles." << endl;
	cout << "4. Array sorting." << endl;
	cout << "5. Number factorial." << endl;
	cout << "6. Is number a Prime" << endl;
	cout << "=========================================" << endl;
	char selection;
	cin >> selection;
	cout << "=========================================" << endl;
	return selection;
}

// printing integers power of two until/including upper bound
void pow2() {
	int end = enterInteger("Please, enter positive integer:", "Error: Your input is not a positive integer", true, false);	
	for (int i = 1; i <= end; i++) {
		cout << "number " << i << " power of 2 is: " << i * i << endl;
	}
}

// finding sum og integer digits
void digitSum() {
	int number = enterInteger("Please, enter integer:", "Error: Your input is not an integer", false, true);
	cout << "Sum of digits of number " << number;
	if (number < 0) number *= -1;
	int sum = 0;
	while (number != 0) {
		sum += number % 10;
		number /= 10;
	}
	cout << " is " << sum << endl;
}

// filtering array (vector) for double entries
void arrayNoDoubles() {
	vector<int> input = {34, 6, 43, 6, 2, 2, 0, -3, -3};
	vector<int> result = {};
	for (int i = 0; i < input.size(); i++) {
		if (find(result.begin(), result.end(), input[i]) != result.end()){
			continue;
		} else {
			result.push_back(input[i]);
		}
	}
	cout << "Original Array: ";
	printVector(input);
	cout << "Array without doubles: ";
	printVector(result); 
}

// printing vector
void printVector(vector<int>& vect){
	size_t size = vect.size();
	cout << "{ ";
	for (int i = 0; i < size; i++) {
		cout << setw(3) << vect[i] << setw(0);
		if (i != size - 1) cout  << ",";
		cout << " ";
	}
	cout << "}" << endl;
}

// array (vector) sorting using sort function
void arraySort() {
	vector<int> input = { 34, 6, 43, 6, 2, 2, 0, -3, -3 };
	cout << "Original array: ";
	printVector(input);
	sort(input.begin(), input.end());
	cout << "Sorted array:   ";
	printVector(input);
}

// finding number factorial
void factorial() {
	bool badInput = true;
	int num = enterInteger("Please, enter a positive integer or 0:", "Error: Your input is not a positive integer or 0", true, true);
	int fact = 1;
	for (int i = 2; i <= num; i++) {
		fact *= i;
	}
	cout << "Iteger " << num << " factorial is " << fact << endl;
}

// input and call of isPrime fuction
void checkPrime() {
	int num = enterInteger("Please, enter an integer:", "Error: Your input is not an integer.", false, true);
	if (isPrime(num)) {
		cout << "Number " << num << " is a Prime number" << endl;
	}
	else {
		cout << "Number " << num << " is not a Prime number" << endl;
	}
}

// checking if number is Prime
bool isPrime(int num) {
	if(num == 2 || num == 3)
		return true;

	if (num <= 1 || num % 2 == 0 || num % 3 == 0)
		return false;

	for (int i = 5; i * i <= num; i += 6)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}

	return true;
}

// input for integers with rudamentary error checking
int enterInteger(string msg, string err_msg, bool onlyPositive, bool allowZero) {
	int input;
	bool endLoop = false;
	while (!endLoop) {
		endLoop = true;
		cout << msg << endl;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << err_msg << endl;
			endLoop = false;
		}
		if (allowZero && input == 0) break;
		if (onlyPositive && input < 1) {
			cin.clear();
			cin.ignore();
			cout << err_msg << endl;
			endLoop = false;
		}
	}
	return input;
}