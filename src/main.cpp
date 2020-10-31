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
	const int hSCREENWIDTH = Screen::SCREEN_WIDTH / 2;
	const int hSCREENHEIGHT = Screen::SCREEN_HEIGHT / 2;
	// Update particles
	do {
		
		
		// Draw particles
		// number of ms since program started
		int elapsed = SDL_GetTicks();
		
		screen.clear();
		swarm.update();
		
		// color changing algorithm
		unsigned char red = (1 + sin(elapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(elapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(elapsed * 0.0003)) * 128;
		
		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::N_PARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * hSCREENWIDTH;
			int y = particle.m_y * hSCREENWIDTH + hSCREENHEIGHT;
			
			screen.setPixel(x, y, red, green, blue);
		}
		
		// Draw the screen
		screen.update();

		// Check for messages/events
	} while (screen.processEvents());

	screen.close();
	return 0;
}
