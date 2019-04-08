#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <time.h>

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
		Population(int n) {
			people = vector<Person>(n); // vector named people with objects of Person
			popsize = n;
			srand(time(NULL));
			for (int i = 0; i < popsize; i++) {
				Person guy;
				people[i] = guy;
			}
		}

		void get_mem(int i) {
			cout << people[i].status_string() << endl;
		}

		void random_infection() {
			while (1) {
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
			    count_infected() << " : ";

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

		void update() {
			int count = 0;
			while (1) {

				count++;

					pop_status(count);

				if (count_infected() == 0) {
					break;
					}

				for (auto &i : people) {
					i.update();
				}

				for (int i = 0; i < popsize; i++) {
					if (1.*rand()/(RAND_MAX) < transfer_prob) {
						if (people[i].status_string() == "sick") {
							transmission(i);
							i++; // prevents daily chains of infection
						}
					}
				}
				
			}
		}

		void set_transfer_prob(float prob) {
			transfer_prob = prob;
		}

		void set_innoculate(float prob) {
			for (auto &i : people) {
				if (1.*rand()/(RAND_MAX) < prob) {
					i.set_status(-2);
				}
			}
		}

		void transmission(int position) { 
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
		}
		void run_sim() {
			float transfer_probability, vac_percent;
			cout << "Daily Transmission Probability (%): ";
			cin >> transfer_probability;
			transfer_probability /= 100;
			cout << "Vaccinated Percentage of Population (%): ";
			cin >> vac_percent;
			vac_percent /= 100;
			set_innoculate(vac_percent);
			set_transfer_prob(transfer_probability);
			random_infection();	// must come after set_innoculate()
			update();
		}
};


// ---------------- Main ----------------- //


int main() {
	Population pop(15);
	pop.run_sim();
	return 0;
}
