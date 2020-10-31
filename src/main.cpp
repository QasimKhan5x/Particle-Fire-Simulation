#include <iostream>
#include <math.h>
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
		// number of ms since program started
		int elapsed = SDL_GetTicks();
		
		// color changing algorithm
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		for(int y=0; y < Screen::SCREEN_HEIGHT; y++) {
			for(int x=0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}
		
		// Draw the screen
		screen.update();

		// Check for messages/events
	} while (screen.processEvents());

	screen.close();
	return 0;
}
