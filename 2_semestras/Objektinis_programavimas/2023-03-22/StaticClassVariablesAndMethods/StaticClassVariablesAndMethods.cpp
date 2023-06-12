/*
Author: Edgaras Jurevicius
Date: 2023-03-15
Group: JNII22
Assigment: Seventh practical assigment (Static Class Variables and Methods)
Revision date 1: 2023-03-21
Revision date 2: 2023-03-22
Revision date 3: 2023-03-30
*/

#include <iostream>
#include "Product.h"
#include "Rectangle.h"
#include "CoffeeMachine.h"

int main()
{
    Product p1("Pen", 3, 0.35);
    Product p2("Paper", 20, 0.05);
    Product p3("Tablet", 2, 650.00);
    std::cout << "================================" << std::endl;
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    std::cout << "================================" << std::endl;
    p3.printCheapest();
    p3.printMostExpensive();
    std::cout << "================================" << std::endl;
    p3.useDiscount(15.00);
    std::cout << "After discount:" << std::endl;
    p1.printInfo();
    p2.printInfo();
    p3.printInfo();
    std::cout << "================================" << std::endl;
    p3.printCheapest();
    p3.printMostExpensive();
    std::cout << "================================" << std::endl;

    Rectangle* rects[3];
    rects[0] = new Rectangle(1.0, 3.0);
    rects[1] = new Rectangle(2.5, -1.5);
    rects[2] = new Rectangle(-2.0, 3.0);

    rects[0]->printInfo();
    rects[1]->printInfo();
    rects[2]->printInfo();

    rects[0]->setStartPoint(-1.0, -1.0);

    rects[0]->printInfo();
    rects[1]->printInfo();
    rects[2]->printInfo();

    for (int i = 2; i > -1; i--) {
        delete rects[i];
    }

    CoffeeMachine cm;

}
