/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-03-01
*/

#pragma once
#include "Staciakampis.h"
#include <iostream>
#include <iomanip>

class StaciakampisGretasienis :
    public Staciakampis
{
protected:
    double height;
    double volume;
public:
    //constructors and destructor
    StaciakampisGretasienis();
    StaciakampisGretasienis(double, double, double);
    ~StaciakampisGretasienis();
    //setters
    void setWidth(double);
    void setLength(double);
    void setHeigth(double);
    //getters
    double getHeight();
    double getVolume();
    //print info
    void printInfo();
    //helper fuctions
    void calculatePerimeter();
    void calculateArea();
    void calculateVolume();
};

