#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include "Person.h"
#include "Population.h"

// create object files with 
// "g++ -c diseasesim.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim


int main() {
	Population pop(20);
	pop.run_sim(1);
	return 0;
}