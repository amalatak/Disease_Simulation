#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::setw;

// ++++++++++++++ Person Class +++++++++++++++++ //


class Person {
	private:
		int status; // persons integer sickness value
		string state; // persons string sickness value
	public:
		Person() {
			status = 0;
		}
		string status_string() {
			if (status == 0) {
				state = "susceptible";
			} else if (status > 0) {
				state = "sick";
			} else if (status == -1) {
				state = "recovered";
			} else {state = "innoculated";}
			return state;
		}
		void set_status(int stat_update) {
			status = stat_update;
		}

		void update() {
			if (status > 1) {
				status--;
			} else if ( status == 1) {
				status = -status;
			}
		}
		void infect(int n) {
			if (status == 0) {
				status = n;
			}
		}
		bool is_stable() {
			if (status == -1) {
				return true;
			} else { return false; }
		}
};


// +++++++++++++ Population Class +++++++++++++++ //

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

// ================ Constructor ===================== //

		Population(int n) {
			people = vector<Person>(n); // vector named people with objects of Person
			popsize = n;
			srand(time(NULL));
			for (int i = 0; i < popsize; i++) {
				Person guy;
				people[i] = guy;
			}
		}

// ============ Access Private Members ============== //

		void get_mem(int i) {
			cout << people[i].status_string() << endl;
		}


		void set_transfer_prob(float prob) {
			transfer_prob = prob;
		}

		void set_innoculate(float prob) {
			for (auto &i : people) {
				if (1.*rand()/(RAND_MAX) < prob) {
					i.set_status(-2);
					num_innoculated++;
				}
			}
		}


		void get_data() { // prints out final statistics
			float percent_susceptible_infected = 100*((1.*num_infected)/(popsize - num_innoculated));
			cout << "days: " << days << endl;
			cout << "percent non innoculated infected: " << percent_susceptible_infected << endl;
		}

// ============= Other Members ==================== //

		void random_infection() {
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

		int count_infected() {
			int count = 0;
			for (auto i : people) {
				if (i.status_string() == "sick") {
					count++; 
				}
			}
			return count;
		}

		void pop_status(int day) {
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

		void transmission() { 
			for (int i = 0; i < popsize; i++) {
				int enc = 0;  // counts encounters
				if (people[i].status_string() == "sick") {  // ensures only sick people do the encountering
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


		void update() {

			days = 0;
			while (1) {
				days++;
				//pop_status(days);
				if (count_infected() == 0) {
					break;
					}

				for (auto &i : people) {
					i.update();
				}

				transmission();
			}
		}


		void run_sim() {
			float transfer_probability, vac_percent;
			cout << "Encounter Transmission Probability (%): ";
			cin >> transfer_probability;
			transfer_probability /= 100;
			cout << "Vaccinated Percentage of Population (%): ";
			cin >> vac_percent;
			vac_percent /= 100;
			set_innoculate(vac_percent);
			set_transfer_prob(transfer_probability);
			random_infection();	// must come after set_innoculate()
			update();
			get_data();
		}
};


// ---------------- Main ----------------- //


int main() {
	Population pop(30000);
	pop.run_sim();
	return 0;
}