/*
Author: Edgaras Jurevicius
Date: 2023-03-01
Group: JNII22
Assigment: Fifth practical assigment (Polymorphism)
Revision date 1:
*/

#pragma once
#include "GeometrineFigura.h"
#include <iomanip>
#include <iostream>

class Trikampis :
    public GeometrineFigura
{
private:
    double base;
    double heigth;
    //helper
    void calculateArea();
public:
    //constructors and destructor
    Trikampis();
    Trikampis(double, double);
    ~Trikampis();
    //setters
    void setBase(double);
    void setHeigth(double);
    //getters
    double getBase();
    double getHeigth();
    //print
    void printArea();
};

