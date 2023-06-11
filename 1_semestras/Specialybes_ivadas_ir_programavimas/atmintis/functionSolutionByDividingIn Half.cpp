#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;

double fepowxminusthreex(double);
double fcosxminusx(double);
//double degreesToRadians(double);
double fminustwoxplusonefourthplussinx(double);
double flogtenxplusxpowthree(double);
double allowedErrorHalf = 0.001;
double dmod(double, double);
void findSolution(double (*)(double), double, double, string);

int main(){

    srand(time(0)); // random seed

    // menu inicilizacija
    bool selected;
    char selection;

    // kintamieji
    double (*FuncY)(double); // nuoroda i funkcija
    string functionExpression; // funcijos tekstine israiska
    // random reziai
    double rightX = dmod((double)rand(), 10.0)*10.0;
    double leftX = rightX * -1;
    // extremumas, nes f-ja f(x) = (e^x) - 3x yra parabole su sakomis i virsu, minimumas gaunasi taske (1.099, -0.296)
    double extremumX = 1.099;

    cout << fixed << setprecision(3); // formataviams

    while (true){ // begalinis ciklas pakartotiniams skaiciavimams
        selected = false; // menu reinicilizacija
        while (!selected){ // menu ciklas
            cout << "Please select function witch solution You want to find:" << endl;
            cout << "1. f(x) = (e^x) - 3x = 0" << endl;
            cout << "2. f(x) = cos(x) - x = 0" << endl;
            cout << "3. f(x) = -2x + 0.25 + sin(x) = 0" << endl;
            cout << "4. f(x) = log10(x) + x^3 = 0" << endl;
            cout << "Input symbol q or Q to stop a program." << endl;
            cin >> selection;
            cout << endl;

            switch (selection){
            // programos stabdymas
            case 'q': case 'Q':
                return 0;
                break;
            case '1':
                selected = true;
                FuncY = fepowxminusthreex;
                functionExpression = "f(x) = (e^x) - 3x = 0";
                // du sprendiniai
                findSolution(FuncY, leftX, extremumX, functionExpression);
                findSolution(FuncY, extremumX, rightX, functionExpression);
                break;
            case '2':
                selected = true;
                FuncY = fcosxminusx;
                functionExpression = "f(x) = cos(x) - x = 0";
                findSolution(FuncY, leftX, rightX, functionExpression);
                break;
            case '3':
                selected = true;
                FuncY = fminustwoxplusonefourthplussinx;
                functionExpression = "f(x) = -2x + 0.25 + sin(x) = 0";
                findSolution(FuncY, leftX, rightX, functionExpression);
                break;
            case '4':
                selected = true;
                FuncY = flogtenxplusxpowthree;
                functionExpression = "f(x) = log10(x) + x^3 = 0";
                findSolution(FuncY, leftX, rightX, functionExpression);
                break;
            default:
                cout << "Error: No such command: " << selection << endl;
            }
        }
        cout << endl;
    }

    return 0;
}

// sprendiniu paieska
void findSolution(double (*FuncY)(double), double leftX, double rightX, string functionExpression){
    double rightY, leftY;
    bool goingDown = false;

    // reziu kur f-ja kerta x asi paieska
    while (true){
        leftY = FuncY(leftX);
        rightY = FuncY(rightX);
        if (leftY > -1 * allowedErrorHalf && leftY < allowedErrorHalf) {
            cout << "Function " << functionExpression << " approximate solution: x = " << leftX << endl;
            return;
        }
        if (rightY > -1 * allowedErrorHalf && rightY < allowedErrorHalf) {
            cout << "Function " << functionExpression << " approximate solution: x = " << rightX << endl;
            return;
        }
        if (leftY < rightY){
            goingDown = false;
            if (leftY < 0 && rightY > 0) break;
            if (leftY > 0){
                rightX = leftX;
                leftX -= leftX;
            } else if (rightY < 0) {
                leftX = rightX;
                rightX += rightX;
            }
        } else {
            goingDown = true;
            if (leftY > 0 && rightY < 0) break;
            if (leftY < 0){
                rightX = leftX;
                leftX -= leftX;
            } else if (rightY > 0){
                leftX = rightX;
                rightX += rightX;
            }
        }
    }

    // sprendinio paieska naudojant binarines paieskos principa
    double middleX, middleY;

    while(true){
        middleX = (leftX + rightX) / 2;
        middleY = FuncY(middleX);
        if (middleY > -1 * allowedErrorHalf && middleY < allowedErrorHalf) {
            cout << "Function " << functionExpression << " approximate solution: x = " << middleX << " Allowed error: " << 2*allowedErrorHalf << endl;
            return;
        }
        if (goingDown){
            if (middleY > 0) {
                leftX = middleX;
            } else {
                rightX = middleX;
            }
        } else {
            if (middleY < 0) {
                leftX = middleX;
            } else {
                rightX = middleX;
            }
        }
    }
}

// f-jos f(x) = (e^x) - 3x reiksmes radimas taske x
double fepowxminusthreex(double x){
    return exp(x) - 3*x;
}

// f-jos f(x) = cos(x) - x reiksmes radimas taske x
double fcosxminusx(double x){
    //return cos(degreesToRadians(x)) - x;
    return cos(x) - x;
}

/*
double degreesToRadians(double deg){
    return deg * 180 / M_PI;
}
*/

// f-jos f(x) = -2x + 0.25 + sin(x) reiksmes radimas taske x
double fminustwoxplusonefourthplussinx(double x){
    //return -2 * x + 0.25 + sin(degreesToRadians(x));
    return -2 * x + 0.25 + sin(x);
}

// f-jos f(x) = log10(x) + x^3 reiksmes radimas taske x
double flogtenxplusxpowthree(double x){
    return log10(x) + pow(x, 3);
}

// liekanos double tipui implementacija
double dmod(double x, double y) {
    return x - (int)(x/y) * y;
}
