#include "Person.h"
#include "Population.h"

// create object files with 
// "g++ -c diseasesim_neighbors_w_innoculation.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim_neighbors_w_innoculation.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim


int main() {
	Population pop(20);
	pop.run_sim(2);
	return 0;
}