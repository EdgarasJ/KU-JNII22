/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>

using namespace std;

unsigned int fibonacci(unsigned int);

int main () {
    unsigned int place;
    cout << "Input a place of number in Fibonacci sequance: ";
    cin >> place;
    cout << "Number in Fibonacci sequence at a place: " << place << " equals to: " << fibonacci(place);
    return 0;
}

// fibonachio sekos numerio nurodytame indekse radimas
unsigned int fibonacci(unsigned int index) {
    if (index == 1 || index == 2) return 1; // pirmos dvi vietos vienetai
    if (index > 2) return fibonacci(index - 1) + fibonacci(index - 2);
    return 0;
}
