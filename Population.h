#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::setw;

class Population {
	private:
		vector<Person> people;
		int popsize;
		float transfer_prob;
		int sick_length = 5;
		int per_day_enc = 5;
		int days, num_innoculated = 0;
		int num_infected = 0;

	public:
		Population(int n);
		void get_mem(int i);
		void set_transfer_prob(float prob);
		void set_innoculate(float prob);
		void get_data();
		void random_infection();
		int count_infected();
		void pop_status(int day);
		void transmission();
		void neigh_transmission();
		void neigh_update();
		void update(bool printflag);
		void run_sim(int n);
};

#endif