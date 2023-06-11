/*
Author: Edgaras Jurevicius
Date: 2023-02-03
Group: JNII22
Assigment: Third practical assigment (composition of Classes)
Revision date 1: 2023-02-04
Revision date 2: 2023-02-09
*/

#include "Taskas.h"
#include "Staciakampis.h"
#include <vector>
#include <iostream>
#include "Darbuotojas.h"
#include "Kugis.h"
#include "Atkarpa.h"

int main()
{
    std::vector<double> coordinates;
    double input;
    std::cout << "Please, input rectange coordinates:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "x = ";
        std::cin >> input;
        coordinates.push_back(input);
        std::cout << "y = ";
        std::cin >> input;
        std::cout << std::endl;
        coordinates.push_back(input);
    }

    Taskas p1(coordinates[0], coordinates[1]);
    Taskas p2(coordinates[2], coordinates[3]);
    Taskas p3(coordinates[4], coordinates[5]);
    Taskas p4(coordinates[6], coordinates[7]);

    Staciakampis rect1(p1, p2, p3, p4);

    if (!rect1.getErrorFlag()) {
        rect1.printInfo();
    }
    
    Darbuotojas employee1(24, 4, 1500.00);
    employee1.printInfo();

    std::cout << "Cone with given altitude:" << std::endl;
    Kugis cone1(2.0, 3.0, 4.0);
    cone1.printInfoAltitude();

    std::cout << "Cone with altitude points: ";
    p1.printCoordsOnly();
    std::cout << " and ";
    p2.printCoordsOnly();
    std::cout << ": " << std::endl;
    Atkarpa alt(p1, p2);
    Kugis cone2(2.0, 3.0, alt);
    cone2.printInfoAltitude();
}
