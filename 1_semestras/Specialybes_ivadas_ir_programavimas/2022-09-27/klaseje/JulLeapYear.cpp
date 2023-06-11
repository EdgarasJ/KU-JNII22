#include <iostream>

using namespace std;

bool isJulLeapYear(int year) {

	return year % 4 == 0;

}

int main() {
	int year;
	cout << "Iveskite metus: " << endl;
	cin >> year;

    if (isJulLeapYear(year)) {
        cout << "Metai: " << year << " yra keliamieji." << endl;
    }
    else {
        cout << "Metai: " << year << " nera keliamieji." << endl;
    }

	return 0;
}
