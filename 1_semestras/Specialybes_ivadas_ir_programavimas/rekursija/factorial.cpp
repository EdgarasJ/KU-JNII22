/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>

using namespace std;

long int factorial(int);

int main () {
    int num;
    cout << "Input number: ";
    cin >> num;
    cout << "Factorial (" << num << "): " << factorial(num);
    return 0;
}

// Skaiciuojamas skaiciaus faktorialas
long int factorial(int num) {
    if (num == 0) return 1; // graziname vieneta jei skaiciuojam nulio faktoriala.
    return num * factorial(num - 1);
}
