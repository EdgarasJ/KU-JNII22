/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-03-01
*/

#pragma once
#include "GeometrineFigura.h"
#include <iostream>
#include <iomanip>

class Staciakampis :
    public GeometrineFigura
{
protected:
    double length;
    double width;
public:
    //constructors and destructor
    Staciakampis();
    Staciakampis(double, double);
    ~Staciakampis();
    // setters
    void setLength(double);
    void setWidth(double);
    // getters
    double getLength();
    double getWidth();
    // print info
    void printInfo();
    // helper functions
    void calculatePerimeter();
    void calculateArea();
};

