/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>
#include <cmath>

using namespace std;

double Power(double, int);

int main () {
    double number;
    int power;
    cout << "Input a base: ";
    cin >> number;
    cout << "Input a power to raise to: ";
    cin >> power;
    cout << "The number " << number << " raised by power of " << power << " is: " << Power(number, power);
    return 0;
}

// skaiciaus kelimas laipsniu
double Power(double number, int power) {
    if (power == 0) return 1; // skaicius pakeltas nuliniu laipsniu yra vienetas
    if (power < 0) return 1.0 / Power(number, abs(power)); // jei keliama neigiamu laipsniu
    return number * Power(number, power - 1); // kelimas teigiamu laipsniu
}
