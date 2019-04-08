#include <iostream>
#include <string>
#include <vector>
#include "Person.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;


// --------------- Person Class ------------------ //


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


int main() {

	int step = 0;
	Person joe;
	while (1) {
		step++;
		joe.update();
		float bad_luck = 1.*rand()/(1.*RAND_MAX);
		if (bad_luck > .95) {
			joe.infect(5);
		}
		cout << "On day " << step << ", Joe is "
			<< joe.status_string() << endl;
		if (joe.is_stable()) {
			break;
		}
	}
}