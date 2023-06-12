/*
Author: Edgaras Jurevicius
Date: 2023-03-22
Group: JNII22
Assigment: Eight practical assigment (Pointers To Functions)
Revision date 1: 2023-04-06
*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Personnel.h"

int getRandom(int _ceil) {
    
    return rand() % _ceil;
}

int main()
{
    Employee emp1;
    emp1.chooseSequenceOrder("in");
    emp1.chooseSequenceOrder("out");

    std::string names[] = {"Harry", "John", "Henry", "Tom", "Robert", "Bert", "Samuel", "Antony", "Steve", "Ann"};
    std::string surnames[] = { "Harrisson", "Johanson", "Henrikson", "Stark", "Robertson", "Pascal", "Jackson", "Turing", "Granger", "Wozniak" };
    std::string proffessions[] = { "Janitor", "CEO", "Programmer", "Secretary", "Administrator", "Lawyer", "Security Guard", "Director", "CTO", "Accountant" };

    srand(time(NULL));

    Personnel pers;
    int rNumber;
    std::string name, surname, proffession;
    unsigned int age, experience;
    double salary;

    Employee* emp;

    for (int i = 0; i < 10; i++) {
        rNumber = getRandom(10);
        name = names[rNumber];
        rNumber = getRandom(10);
        surname = surnames[rNumber];
        rNumber = getRandom(10);
        proffession = proffessions[rNumber];
        rNumber = getRandom(80);
        age = rNumber + 18;
        rNumber = getRandom(5);
        experience = age - 18 - rNumber;
        experience = (experience < 0) ? 0 : experience;
        rNumber = getRandom(3000);
        salary = double(rNumber);
        emp = new Employee(name, surname, proffession, age, experience, salary);
        pers.addEmployee(emp);
    }

    pers.filterByCategories();
    pers.filterInRange();
}
