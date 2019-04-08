#include "Person.h"
#include "Population.h"

// create object files with 
// "g++ -c diseasesim_spread.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim_spread.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim


int main() {
	Population pop(20);
	pop.run_sim(3);
	return 0;
}