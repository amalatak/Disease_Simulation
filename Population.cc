#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include "Population.h"
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::setw;


// +++++++++++++ Population Class +++++++++++++++ //



// ================ Constructor ===================== //

Population::Population(int n) {
	people = vector<Person>(n);    // vector named people with objects of Person
	popsize = n;
	srand(time(NULL));             // seeds random number generator to be more random
	for (int i = 0; i < popsize; i++) { // fills the vector with Person objects
		Person guy;
		people[i] = guy;
	}
}

// ============ Access Private Members ============== //

void Population::get_mem(int i) { // gets the string status of the Person at the ith element
	cout << people[i].status_string() << endl;
}


void Population::set_transfer_prob(float prob) { // sets the disease transmission probability for an encounter
	transfer_prob = prob;
}

void Population::set_innoculate(float prob) { // innoculates a fraction of the population
	for (auto &i : people) {
		if (1.*rand()/(RAND_MAX) < prob) {
			i.set_status(-2);
			num_innoculated++;
		}
	}
}


void Population::get_data() { // prints out final statistics if using large data sets
	float percent_susceptible_infected = 100*((1.*num_infected)/(popsize - num_innoculated));
	cout << "days: " << days << endl;
	cout << "percent non innoculated infected: " << percent_susceptible_infected << endl;
}

// ============= Other Members ==================== //

void Population::random_infection() { // randomly infects one Person in the population
	int count = 0;
	while (count < 1000) {
		count++;
		int randloc = rand()%popsize;
		if (people[randloc].status_string() != "innoculated") {
			people[randloc].infect(sick_length);
			break;
		}
	}
}

int Population::count_infected() { // returns an int counting the number of people currently infected
	int count = 0;
	for (auto i : people) {
		if (i.status_string() == "sick") {
			count++; 
		}
	}
	return count;
}

void Population::pop_status(int day) { 
	
	// prints the graphic displaying the status of the population
	// + ==> sick
	// - ==> recovered
	// O ==> susceptible
	// I ==> innoculated

	cout << "On day   " << setw(4) << day << " # sick:   " <<
	    setw(3) << count_infected() << " : ";

	for (auto i : people) {
		if (i.status_string() == "sick") {
			cout << " + ";
		}
		else if (i.status_string() == "susceptible") {
			cout << " O ";
		}
		else if (i.status_string() == "recovered") {
			cout << " - ";
		}
		else {cout << " I ";}
	}
	cout << endl;
}

void Population::transmission() { // spreads disease randomly to anyone in the population
	for (int i = 0; i < popsize; i++) {
		int enc = 0;  // counts encounters
		if (people[i].status_string() == "sick") {  
			// if statements prevents susceptible people from encountering
			// sick people, ensures that sick people only contact a set number of 
			// people per day
			while (enc < per_day_enc) {
				int person_enc = (rand()%popsize);
				if (person_enc != i) {
					enc++; 
					float prob = (1.*rand())/(RAND_MAX);
					if (prob < transfer_prob) {
						if (people[person_enc].status_string() == "susceptible") {
							people[person_enc].infect(sick_length);
							num_infected++;
						}
					}
				}
			}
		}
	}
}


void Population::neigh_transmission() {  // spreads disease to only a neighbor of a sick person
	for (int position = 0; position < popsize; position++) {
			if (1.*rand()/(RAND_MAX) < transfer_prob) {
				if (people[position].status_string() == "sick") {
					if (position == 0) {
						if (people[1].status_string() == "susceptible") {
							people[1].infect(sick_length);
						}
					}

					else if (position == popsize - 1) {
						if (people[popsize - 2].status_string() == "susceptible") {
							people[popsize - 2].infect(sick_length);
						}
					}
					else {
						if (people[position - 1].status_string() == "susceptible") {
							people[position - 1].infect(sick_length);
						}
						if (people[position + 1].status_string() == "susceptible") {
						people[position + 1].infect(sick_length);
					}
				}
				position++; // prevents daily chains of infection
			}
		}
	}
}


void Population::update(bool printflag) {

	// updates the population when simulating a spread of 
	// disease to random individuals

	days = 0;
	while (1) {
		days++;

		if (printflag) {
			pop_status(days);
		}
		
		if (count_infected() == 0) {
			break;
		}

		for (auto &i : people) {
			i.update();
		}

		transmission();
	}
}

void Population::neigh_update() {

	// updates the population when simulating a transfer of
	// disease to only neighbors

	days = 0;
	while (1) {
		days++;

		pop_status(days);
		
		if (count_infected() == 0) {
			break;
		}

		for (auto &i : people) {
		i.update();
		}

		neigh_transmission();
	}
}


// ========== Simulation Member ============= //

void Population::run_sim(int n) { // contains all cases for the simulation


	// n = 0 ==> simulate for one person
	// n = 1 ==> simulate for transmission among neighbors
	// n = 2 ==> simulate with vaccination among neighbors
	// n = 3 ==> simulate spreading within a population
	// n = 4 ==> simulate spreading with a large population

	float transfer_probability, vac_percent;
	
	transfer_probability = 0;
	vac_percent = 0;


	if (n == 0) {
		random_infection();
		neigh_update();
	}

	else {

		cout << "Encounter Transmission Probability (%): ";
		cin >> transfer_probability;
		transfer_probability /= 100;
		set_transfer_prob(transfer_probability);

		if (n == 1) {
			random_infection();	
			neigh_update();
		}

		
	
		else {
			cout << "Vaccinated Percentage of Population (%): ";
			cin >> vac_percent;
			vac_percent /= 100;
			set_innoculate(vac_percent);
			random_infection();	        // must come after set_innoculate()
			
			if (n == 2) {
				neigh_update();
			}

			else if (n == 3) {
				update(1);
			}

			else if (n == 4) {
				update(0);
				get_data();
			}
		}
	}
}


