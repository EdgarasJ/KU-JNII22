/*
Author: Edgaras Jurevicius
Date: 2023-02-15
Group: JNII22
Assigment: Fourth practical assigment (Inheritance)
Revision date 1: 2023-02-23
*/

#pragma once
#include "Asmuo.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

class Studentas :
    public Asmuo
{
private:
    std::string id;
    std::vector<std::string> subjects;
    float averageScore;
public:
    //constructors and destructors
    Studentas();
    Studentas(std::string, std::vector<std::string>, float);
    Studentas(std::string, std::string, unsigned short int, std::string, std::vector<std::string>, float);
    ~Studentas();
    //setters
    void setId(std::string);
    void setSubjects(std::vector<std::string>);
    void setAverageScore(float);
    //getters
    std::string getId();
    std::vector<std::string> getSubjects();
    float getAverageScore();
    //print info
    void printInfo();
};

