#include "Person.h"
#include "Population.h"


// create object files with 
// "g++ -c diseasesim_notrans.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim_notrans.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim


int main() {
	Population pop(10);
	pop.run_sim(0);
	return 0;
}