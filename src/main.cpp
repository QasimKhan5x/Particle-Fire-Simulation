#include <iostream>
#include "Screen.cpp"
using namespace std;
using namespace pfs;

int main(int argv, char** args) {

	Screen screen;
	
	if(!screen.init()) {
		cout << "Error initialising screen." << endl;
	}
	
	do {
		// Update particles
		
		// Draw particles
		for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
			for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}
		
		screen.setPixel(400, 300, 255, 255, 255);

		// Draw the screen
		screen.update();

		// Check for messages/events
	} while (screen.processEvents());

	screen.close();
	return 0;
}
