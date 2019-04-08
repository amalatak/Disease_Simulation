#include <iostream>
#include "Person.h"


int main() {


	float susceptibility = .95;
	float days_infected = 5;
	
	cout << "Program working..." << endl;
	int step = 0;
	Person joe;
	while (1) {
		step++;
		joe.update();
		float bad_luck = 1.*rand()/(1.*RAND_MAX);
		if (bad_luck > susceptibility) {
			joe.infect(days_infected);
		}
		cout << "On day " << step << ", Joe is "
			<< joe.status_string() << endl;
		if (joe.is_stable()) {
			break;
		}
	}
}
