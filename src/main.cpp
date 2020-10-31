#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.cpp"
#include "Swarm.cpp"

using namespace std;
using namespace pfs;

int main(int argv, char** args) {

	srand(time(NULL));
	Screen screen;
	
	if(!screen.init()) {
		cout << "Error initialising screen." << endl;
	}
	
	Swarm swarm;
	
	do {
		// Update particles
		
		// Draw particles
		// number of ms since program started
		int elapsed = SDL_GetTicks();
		
		// color changing algorithm
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;
			
			screen.setPixel(x, y, red, green, blue);
		}
		
		// Draw the screen
		screen.update();

		// Check for messages/events
	} while (screen.processEvents());

	screen.close();
	return 0;
}
