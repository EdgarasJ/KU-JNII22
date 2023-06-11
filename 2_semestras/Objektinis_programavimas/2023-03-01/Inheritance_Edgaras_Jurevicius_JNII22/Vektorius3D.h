/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include "Vektorius2D.h"
#include <iostream>
#include <iomanip>
#include <cmath>

class Vektorius3D :
    public Vektorius2D
{
private:
    double z;
public:
    //constructors and destructor
    Vektorius3D();
    Vektorius3D(double, double, double);
    ~Vektorius3D();
    //setters
    void setZ(double);
    //getters
    double getZ();
    double getLength();
    //print info
    void printInfo();
};

