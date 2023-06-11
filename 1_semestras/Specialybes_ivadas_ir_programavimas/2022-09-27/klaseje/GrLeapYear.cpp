#include <iostream>

using namespace std;

bool isGrLeapYear(int year) {

	if ((year % 100 == 0 && (year / 100) % 4 == 0 ) || (year % 100 != 0 && year % 4 == 0) ) return true;

    return false;

}

bool isJulLeapYear(int year) {

	return year % 4 == 0;

}

int main() {
	int year;
	cout << "Iveskite metus: " << endl;
	cin >> year;

    if (isGrLeapYear(year)) {
        cout << "Metai (pagal Gregaliaus): " << year << " yra keliamieji." << endl;
    }
    else {
        cout << "Metai (pagal Gregaliaus): " << year << " nera keliamieji." << endl;
    }

    if (isJulLeapYear(year)) {
        cout << "Metai (pagal Juliaus): " << year << " yra keliamieji." << endl;
    }
    else {
        cout << "Metai (pagal Juliaus): " << year << " nera keliamieji." << endl;
    }

	return 0;
}
