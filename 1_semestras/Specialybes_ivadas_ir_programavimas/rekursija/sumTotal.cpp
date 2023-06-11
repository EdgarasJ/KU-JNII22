/*
Author: Edgaras Jurevicius
Date: 2022-10-18
*/

#include <iostream>

using namespace std;

double sumTotal();

int main () {
    cout << "Ivedinekite skaicius is eiles. Neigiamas skaicius - ivedimo pabaiga." << endl;
    double sum = sumTotal(); // tarpinis kintamasis, kad parametru ivedimas neisiterptu i atsakymo isvedima
    cout << "Teigiamu skaiciu suma: " << sum << endl;
    return 0;
}

//skaiciuojama ivestu teigiamu skaicu suma.
double sumTotal() {
    double num;
    cin >> num;
    if (num < 0) return 0; // skaicius neigiamas todel i suma neieina ir nutraukia rekursini funkcijos kvietima.
    return num + sumTotal();
}
