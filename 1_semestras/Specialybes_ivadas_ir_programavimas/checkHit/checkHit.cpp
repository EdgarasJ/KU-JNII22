#include <iostream>
#include <cmath>

using namespace std;

bool isGrLeapYear(int year) {

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) return true;

    return false;

}

bool isJulLeapYear(int year) {

    return year % 4 == 0;

}

bool isInside1(double x, double y) {
    if (y < 0 || y > 1) return false;
    if (y >= abs(x)) return true;
    return false;
}

bool isInside2(double x, double y) {
    // Uztenka patikrinti ketvirti su teigiamomis x, y reiksmemis, del simetriskumo x, y asimis.
    if (abs(y) < abs(abs(x) - 1.0)) return false;
    // Apskritimo lygtis: x^2 + y^2 = r^2 (^2 - kelimas kvadratu).
    if (abs(y) > abs(sqrt(1 - pow(x, 2)))) return false;
    return true;
}

bool isInside3(double x, double y) {
    // galima naudoti abs(x), nes figura simetriska y asies atzvilgiu
    if (y > 0 || y < -1) return false;
    // Apskritimo lygtis: (x - a)^2 + (y -b)^2 = r^2 , a = 1 ir b = 0 - centro koordinates
    if (y > -sqrt(1 - pow(abs(x) - 1.0, 2))) return true;
    return false;
}

int main() {

    /*Uzduotis: Nustatyti ar nurodyti metai yra keliamieji pagal Juliaus ir Grigaliaus kalendorius*/
    /*
    int year;
    cout << "Iveskite metus: " << endl;
    cin >> year;

    if (isGrLeapYear(year)) {
        cout << "Metai (pagal Grigaliaus): " << year << " yra keliamieji." << endl;
    }
    else {
        cout << "Metai (pagal Grigaliaus): " << year << " nera keliamieji." << endl;
    }

    if (isJulLeapYear(year)) {
        cout << "Metai (pagal Juliaus): " << year << " yra keliamieji." << endl;
    }
    else {
        cout << "Metai (pagal Juliaus): " << year << " nera keliamieji." << endl;
    }
    */

    /* Uzduotis: Nustatyti ar duotas taskas patenka i figuros, aprasytos funkcijomis y = 1 ir y = abs(x), apimama plota */
    /*
    double x, y;
    cout << "Iveskite tasko x ir y reiksmes: " << endl;
    cin >> x >> y;

    if (isInside1(x, y)) {
        cout << "Taskas (" << x << "; " << y << ") patenka i figuros plota" << endl;
    } else {
        cout << "Taskas (" << x << "; " << y << ") nepatenka i figuros plota" << endl;
    }
    */

    /* Uzduotis: Nustatyti ar duotas taskas patenka i figuros, aprasytos vienetiniu apskritimu ir rombu, apimama plota  */
    /*
    double x, y;
    cout << "Iveskite tasko x ir y reiksmes: " << endl;
    cin >> x >> y;

    if (isInside2(x, y)) {
        cout << "Taskas (" << x << "; " << y << ") patenka i figuros plota" << endl;
    } else {
        cout << "Taskas (" << x << "; " << y << ") nepatenka i figuros plota" << endl;
    }
    */

    /* Uzduotis: Nustatyti ar duotas taskas patenka i figuros, aprasytos dviem vienetiniu apskritimu pusemis zemiau y asies
     simetriskomis y asies atzvilgiu, apimama plota (papildoma uzduotis - "papludimys")*/

    double x, y;
    cout << "Iveskite tasko x ir y reiksmes: " << endl;
    cin >> x >> y;

    if (isInside3(x, y)) {
        cout << "Taskas (" << x << "; " << y << ") patenka i figuros plota" << endl;
    } else {
        cout << "Taskas (" << x << "; " << y << ") nepatenka i figuros plota" << endl;
    }

    return 0;
}

