//I affirm that all code given below was written solely by me, Justice Martinez,
//and that any help I received adhered to the rules stated for this exam.
//Exam #2 Bloomsday Race
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include "Runner.h"

using namespace std;

int main() {

	fstream runners("registrants.txt", ios::in | ios::out);

	if (runners.fail()) {
		cout << "registrants.txt file does not exist.\nExit Program\n";
		return 0;
	}

	int size = 1000;
	
	vector <Runner> registrant(size);

	string firstname, lastname;
	int pace;
	for (int i = 0; i < size; i++) {
		runners >> firstname >> lastname >> pace;
		registrant[i] = Runner(firstname, lastname, pace);
	}

	runners.close();

	for (int j = 0; j < size-1; j++) {
		for (int k = j + 1; k < size; k++){
			if (registrant[k].get_pace() < registrant[j].get_pace()){
				Runner temp = registrant[j];
				registrant[j] = registrant[k];
				registrant[k] = temp;
			}
		}
	}
	
	ofstream whiteRunners("white.txt");
	ofstream yellowRunners("yellow.txt");
	ofstream greenRunners("green.txt");
	ofstream orangeRunners("orange.txt");
	ofstream blueRunners("blue.txt");
	ofstream lilacRunners("lilac.txt");
	ofstream redRunners("red.txt");

	for (int a = 0; a < size; a++) {
		if (registrant[a].get_pace() <= 360) {
			whiteRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 360 && registrant[a].get_pace() <= 420) {
			yellowRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 420 && registrant[a].get_pace() <= 480) {
			greenRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 480 && registrant[a].get_pace() <= 540) {
			orangeRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 540 && registrant[a].get_pace() <= 600) {
			blueRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 600 && registrant[a].get_pace() <= 720) {
			lilacRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else if (registrant[a].get_pace() > 720 && registrant[a].get_pace() <= 1200) {
			redRunners << registrant[a].get_firstname() << " " << registrant[a].get_lastname() << " " << registrant[a].get_pace() << endl;
		}

		else {
			whiteRunners.close();
			yellowRunners.close();
			greenRunners.close();
			orangeRunners.close();
			blueRunners.close();
			lilacRunners.close();
			redRunners.close();
			break;
		}
	}

	return 0;
}