#include <iostream>
#include "Screen.cpp"
using namespace std;
using namespace pfs;

int main(int argv, char** args) {

	Screen screen;

	if(!screen.init()) {
		cout << "Error initialising screen." << endl;
	}

	/*
	Update particles
	Draw particles
	Check for messages/events
	*/	
	while (screen.processEvents());

	screen.close();

	return 0;
}
