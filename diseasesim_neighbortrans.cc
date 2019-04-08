#include "Person.h"
#include "Population.h"

// create object files with 
// "g++ -c diseasesim_neighbortrans.cc Person.cc Population.cc"
// link object files into executible with
// "g++ diseasesim_neighbortrans.o Person.o Population.o -o diseasesim"
// diseasesim is the executable - run with ./diseasesim

int main() {
	Population pop(15);
	pop.run_sim(1);
	return 0;
}