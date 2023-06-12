/*
Author: Edgaras Jurevicius
Date: 2023-04-11
Group: JNII22
Assigment: Ninth practical assigment (STL library)
Revision date 1: 2023-04-12
Revision date 2: 2023-04-19
Revision date 3: 2023-04-20
*/

#include "PersonalSchedule.h"

//constructor and destructor
PersonalSchedule::PersonalSchedule() {
	std::list<std::string> lst = {};
	schedule.insert(std::pair<std::string, std::list<std::string>>("Sunday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Monday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Tuesday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Wednesday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Thursday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Friday", lst));
	schedule.insert(std::pair<std::string, std::list<std::string>>("Saturday", lst));
	showSchedule();
}
PersonalSchedule::~PersonalSchedule(){}

// helper
std::string PersonalSchedule::inputTask() {
	std::string taskStr = "";
	std::cout << "Please input task text:" << std::endl;
	//std::cin >> taskStr;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, taskStr);
	while (taskStr == "") {
		;
	}
	return taskStr;
}

std::list<std::string>::iterator PersonalSchedule::getListIterator(std::string _day, int _taskPos) {
	std::list<std::string>::iterator it = schedule[_day].begin();
	if (_taskPos < 1) {
		_taskPos = 1;
	}
	if (_taskPos > schedule[_day].size()) {
		it = schedule[_day].end();
	}
	else if (_taskPos == 1) {
		it = schedule[_day].begin();
	}
	else {
		it = std::next(it, _taskPos - 1);
	}
	return it;
}

// add and remove
void PersonalSchedule::addTask(std::string _day) {
	std::string taskStr = inputTask();
	int taskPos;
	std::cout << "Please input task position:" << std::endl;
	std::cin >> taskPos;
	std::list<std::string>::iterator it = getListIterator(_day,taskPos);
	schedule[_day].insert(it, taskStr);
}
void PersonalSchedule::removeTask(std::string _day) {
	int taskPos;
	std::cout << "Please, input position of task You want to remove:" << std::endl;
	std::cin >> taskPos;
	std::list<std::string>::iterator it = getListIterator(_day, taskPos);
	it = schedule[_day].erase(it);
}
// show
void PersonalSchedule::showSchedule() {
	bool exit = false;
	bool found = false;
	std::string choice;
	while (!exit) {
		found = false;
		std::cout << "Please, input day of the week (Sunday - Saturday) or 'quit' to quit:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cin.sync();
		//std::cin >> std::ws;
		std::cin >> choice;
		if (choice == "quit") {
			exit = true;
			found = true;
		}
		if (choice == "Sunday" || choice == "Monday" || choice == "Tuesday" || choice == "Wednesday" || choice == "Thursday" || choice == "Friday" || choice == "Saturday") {
			found = true;
			showDay(choice);
			exit = true;
		}
		if (!found) {
			std::cout << "Error: wrong selection, try: 'quit' or any week day, e.g. 'Tuesday'." << std::endl;
		}
	}
}
void PersonalSchedule::showDay(std::string _day) {
	bool exit = false;
	while (!exit) {
		std::cout << _day << ":" << std::endl;
		int i = 1;
		for (std::string str : schedule[_day]) {
			std::cout << i++ << ". " << str << std::endl;
		}
		std::cout << "Do You want to modyfy schedule? " << std::endl;
		std::cout << "1. Add task" << std::endl;
		std::cout << "2. Remove task" << std::endl;
		std::cout << "3. Go back" << std::endl;

		char ch;
		std::cin >> ch;
		switch (ch)
		{
		case '1':
			addTask(_day);
			break;
		case '2':
			removeTask(_day);
			break;
		case '3':
			exit = true;
			showSchedule();
			break;
		default:
			std::cout << "Error: wrong selection." << std::endl;
			break;
		}
	}
}
