/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1: 2023-04-19
Revision date 2: 2023-04-20
*/

#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <sstream>
#include <limits>

class PersonalSchedule
{
private:
	std::map<std::string, std::list<std::string>> schedule;
	//helper
	void showDay(std::string);
	// helper
	std::string inputTask();
	std::list<std::string>::iterator getListIterator(std::string, int);
public:
	//constructor and destructor
	PersonalSchedule();
	~PersonalSchedule();
	// add and remove
	void addTask(std::string);
	void removeTask(std::string);
	// show
	void showSchedule();
};

