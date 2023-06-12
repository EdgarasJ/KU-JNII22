/*
Author: Edgaras Jurevicius
Date: 2023-03-02
Group: JNII22
Assigment: Sixth practical assigment (Templates and Exceptions)
Revision date 1: 2023-03-08
*/

#include <iostream>
#include <iomanip>
#include "Rectangle.h"
#include "Triangle.h"
#include "EmployeeManyErrClasses.h"
#include "EmployeeOneErrClass.h"

int main()
{
	// ======= Rectangle with templates ===============================================================

	std::cout << "Rectangle with templates :" << std::endl;

	Rectangle <int, int, int> r1(2, 3);
	Rectangle <double, double, double> r2(2.0, 3.0);
	Rectangle <int, double, double> r3(2, 3.0);
	r1.printInfo();
	r2.printInfo();
	r3.printInfo();

	// ======= Triangle with Error Class ===============================================================
	
	std::cout << "Triangle with Error Class :" << std::endl;

	try {
		Triangle t1(1.0, 1.0, 3.0);
		t1.printInfo();
	}
	catch (Triangle::TooLong err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrorMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		Triangle t2(2.0, 2.0, 2.0);
		t2.printInfo();
	}
	catch (Triangle::TooLong err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrorMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	
	// ======= Employee with many Error Classes ===============================================================

	std::cout << "Employee with many Error Classes :" << std::endl;

	try {
		EmployeeManyErrClasses e1;
		e1.printInfo();
	}
	catch (EmployeeManyErrClasses::ErrAge errA) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errA.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrExp errE) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errE.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrSalary errS) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errS.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeManyErrClasses e2(17, 0.0, 600.0);
		e2.printInfo();
	}
	catch (EmployeeManyErrClasses::ErrAge errA) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errA.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrExp errE) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errE.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrSalary errS) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errS.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeManyErrClasses e3(18, 1.0, 600.0);
		e3.printInfo();
	}
	catch (EmployeeManyErrClasses::ErrAge errA) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errA.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrExp errE) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errE.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrSalary errS) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errS.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeManyErrClasses e4(24, 5.0, 400.0);
		e4.printInfo();
	}
	catch (EmployeeManyErrClasses::ErrAge errA) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errA.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrExp errE) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errE.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrSalary errS) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errS.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeManyErrClasses e5(73, 3.0, 200.0);
		e5.printInfo();
	}
	catch (EmployeeManyErrClasses::ErrAge errA) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errA.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrExp errE) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errE.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	catch (EmployeeManyErrClasses::ErrSalary errS) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << errS.getErrMsg() << std::endl;
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	// ======= Employee with one Error Class ===============================================================

	std::cout << "Employee with one Error Class :" << std::endl;

	try {
		EmployeeOneErrClass em1;
		em1.printInfo();
	}
	catch (EmployeeOneErrClass::ErrorEmpl err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrMsg();
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeOneErrClass em2(17, 0.0, 600.0);
		em2.printInfo();
	}
	catch (EmployeeOneErrClass::ErrorEmpl err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrMsg();
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeOneErrClass em3(18, 1.0, 600.0);
		em3.printInfo();
	}
	catch (EmployeeOneErrClass::ErrorEmpl err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrMsg();
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}

	try {
		EmployeeOneErrClass em4(24, 5.0, 400.0);
		em4.printInfo();
	}
	catch (EmployeeOneErrClass::ErrorEmpl err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrMsg();
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	
	try {
		EmployeeOneErrClass em5(73, 76.0, 200.0);
		em5.printInfo();
	}
	catch (EmployeeOneErrClass::ErrorEmpl err) {
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
		std::cout << err.getErrMsg();
		std::cout << std::setfill('=') << std::setw(50) << "=" << std::setw(0) << std::setfill(' ') << std::endl;
	}
	
}

