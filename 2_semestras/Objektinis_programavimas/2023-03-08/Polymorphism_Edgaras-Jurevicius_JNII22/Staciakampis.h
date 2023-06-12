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

class Staciakampis :
    public GeometrineFigura
{
private:
    double length;
    double width;
    //helper
    void calculateArea();
public:
    //constructors and destructor
    Staciakampis();
    Staciakampis(double, double);
    ~Staciakampis();
    //setters
    void setLength(double);
    void setWidth(double);
    //getters
    double getLength();
    double getWidth();
    //print
    void printArea();
};

