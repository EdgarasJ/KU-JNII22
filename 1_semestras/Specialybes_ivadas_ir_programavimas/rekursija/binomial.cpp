/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>

using namespace std;

long int binomialCoeffC(int, int);

int main () {
    int n, m;
    cout << "Input number of elements in a set (n): ";
    cin >> n;
    cout << "Input how much you want to choose from a set (m): ";
    cin >> m;
    if (m > n) {
        cout << "Error. You can't choose more elements than number of elements existing in set."
        return 1;
    }
    cout << "Binomial coefficient C(m,n) equals to: " << binomialCoeffC(m, n);
    return 0;
}

// Skaiciuojamas niutono binomas
long int binomialCoeffC(int m, int n) {
    if (m == 0 || m == n) return 1; // graziname 1 jei imam 0 arba visus elementus is aibes.
    if (m > 0 && m < n) return binomialCoeffC(m, n - 1) + binomialCoeffC(m - 1, n - 1);
}
