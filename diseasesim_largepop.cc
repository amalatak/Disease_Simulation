#include "Person.h"
#include "Population.h"

// create object files with 
// "g++ -c diseasesim_largepop.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim_largepop.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim


int main() {
	Population pop(30000);
	pop.run_sim(4);
	return 0;
}