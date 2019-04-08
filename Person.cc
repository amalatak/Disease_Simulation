// Compile object file with "g++ -c Person_Class.cc Person.cc"
// Must link object ".o" files:
// "g++ Person.o main.o" and in this case, 
// main.o is Person_Class.cc
// save to an executable:
// "g++ Person_Class.o Person.o -o outname"


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;



Person::Person() {
	status = 0;
}

string Person::status_string() {
	if (status == 0) {
		state = "susceptible";
	} else if (status > 0) {
		state = "sick";
	} else if (status == -1) {
		state = "recovered";
	} else {state = "innoculated";}
	return state;
}

void Person::set_status(int stat_update) {
	status = stat_update;
}

void Person::update() {
	if (status > 1) {
		status--;
	} else if ( status == 1) {
		status = -status;
	}
}
void Person::infect(int n) {
	if (status == 0) {
		status = n;
	}
}
bool Person::is_stable() {
	if (status == -1) {
		return true;
	} else { return false; }
}