#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /* Uzdavinys Nr.1:
    B=True, jei x=y, priesingu atveju B=False.
    */
    /*
    int x, y;
    bool B;
    cout << "Iveskite x reiksme: ";
    cin >> x;
    cout << "Iveskite y reiksme: ";
    cin >> y;
    B = x == y;
    cout << "B reiksme: " << (bool)B;
    */

    /* Uzdavinys Nr.2:
                                2      3      4
                               x      x      x
    Apskaiciuoti: y = 1 + x + ---- + ---- + ----
                               2!     3!     4!
    */
    /*
    double x;
    cout << "Iveskite x reiksme: ";
    cin >> x;
    double x2 = x * x;
    double x3 = x2 * x;
    double x4 = x3 * x;
    double fak2 = 2;
    double fak3 = fak2 * 3;
    double fak4 = fak3 * 4;
    double y = 1 + x + x2 / fak2 + x3 / fak3 + x4 / fak4;
    cout << "y reiksme: " << y;
    */
    /*Uzduotis Nr.3:
    
                             -8  m1 * m2
    Apskaiciuoti F = 6,673*10  * -------
                                     2
                                    R
    */
    /*
    double m1, m2, R, F;
    cout << "Iveskite m1 reiksme: ";
    cin >> m1;
    cout << "Iveskite m2 reiksme: ";
    cin >> m2;
    cout << "Iveskite R reiksme: ";
    cin >> R;
    F = 6.673e-8 * ((m1 * m2) / (R * R));
    cout << "F reiksme: " << F;
    */

    /* Uzduotis Nr.4:
    Apskaiciuoti atstuma tarp tasku kuriu koordinates (x1 y1); (x2 y2)
    */
    /*
    int x1, x2, y1, y2;
    double result;
    cout << "Iveskite x1 reiksme: ";
    cin >> x1;
    cout << "Iveskite y1 reiksme: ";
    cin >> y1;
    cout << "Iveskite x2 reiksme: ";
    cin >> x2;
    cout << "Iveskite y2 reiksme: ";
    cin >> y2;
    result = sqrt((double)((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    cout << "Atstumas tarp duotu tasku: " << result << endl;
    */
    /* Uzduotis Nr.5:
    Apskaiciuoti sin(30) ir isitikinti ar 1/2
    */
    /*
    double pi = 3.1415926;
    double radians = 30 * pi / 180;
    cout << "sin(30) = " << sin(radians) << endl;
    */
    /* Uzduotis Nr.6:
    Sukeisti x ir y reiksmes vietomis
    */
    /*
    int x, y;
    cout << "Iveskite x reiksme: ";
    cin >> x;
    cout << "Iveskite y reiksme: ";
    cin >> y;
    x += y;
    y = x - y;
    x -= y;
    cout << "Nauja x reiksme: " << x << endl;
    cout << "Iveskite y reiksme: " << y << endl;
    */
    /* Uzduotis Nr.7:
    Isvesti i ekrana matrica:

    a
     3  6
    a  a
     6  3
    a  a  a
    */
    /*
    int a, a3, a6;
    cout << "Iveskite a reiksme: ";
    cin >> a;
    a3 = a * a * a;
    a6 = a3 * a3;
    cout << endl;
    cout << a << endl << a3 << " " << a6 << endl << a6 << " " << a3 << " " << a << endl;
    */
    /* Uzduotis Nr.8:
                  pi      e
    Kas didesnis e   ar pi
    */
    /*
    double pi = 3.1415926;
    double e = 2.7182818;
    double epi = pow(e, pi);
    double pie = pow(pi, e);
    cout << "e ^ pi reiksme: " << epi << endl;
    cout << "pi ^ e reiksme: " << pie << endl;
    cout << "Ar e ^ pi didesnis uz pi ^ e : " << (epi > pie) << endl;
    */
    /* Uzduotis Nr.9:
    Apskaiciuokite naturinio trizenklio skaiciaus skaitmenu suma
    */

    int skaicius;
    cout << "Iveskite trizenkli skaiciu: ";
    cin >> skaicius;
    int suma = skaicius % 10;
    suma += skaicius / 100;
    suma += (skaicius / 10) % 10;
    cout << "Skaiciaus skaitmenu suma: " << suma << endl;
}
