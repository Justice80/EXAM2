#ifndef RUNNER_H
#define RUNNER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Runner {
private:
	string firstname, lastname;
	int pace;
public:
	Runner() {
		firstname = " ";
		lastname = " ";
		pace = 0;
	}

	Runner(string fname, string lname, int time) {
		firstname = fname;
		lastname = lname;
		pace = time;
	}

	string get_firstname() { return firstname; }
	string get_lastname() { return lastname; }
	int get_pace() { return pace; }
};

#endif