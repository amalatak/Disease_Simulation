#ifndef POPULATION__NEIGHBORS_H
#define POPULATION__NEIGHBORS_H

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

	public:
		Population(int n);
		void get_mem(int i);
		void set_transfer_prob(float prob);
		void set_innoculate(float prob);
		void get_data();
		void random_infection();
		int count_infected();
		void pop_status(int day);
		void transmission(int position);
		void update();
		void run_sim();
};

#endif