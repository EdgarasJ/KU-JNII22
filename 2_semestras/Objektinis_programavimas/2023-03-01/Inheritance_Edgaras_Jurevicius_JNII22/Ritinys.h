/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include "Skritulys.h"
#include <iostream>
#include <iomanip>

class Ritinys :
    public Skritulys
{
private:
    double altitude;
public:
    //constructors and destructor
    Ritinys();
    Ritinys(double);
    Ritinys(double, double);
    ~Ritinys();
    // setters
    void setAltitude(double);
    // getters
    double getAltitude();
    double getVolume();
    //print info
    void printInfo();
};

