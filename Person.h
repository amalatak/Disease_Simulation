#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

class Person {
	private:
		int status; // persons integer sickness value
		string state; // persons string sickness value
	public:
		Person();
		void set_status(int stat_update);
		string status_string();
		void update();
		void infect(int n);
		bool is_stable();
};

#endif