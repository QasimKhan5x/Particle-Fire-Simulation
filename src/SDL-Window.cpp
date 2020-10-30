#include <iostream>
#include "SDL2/SDL.h"
using namespace std;

int main(int argc, char* args[]) {
	
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL init failed." << endl;
		return 1;
	}
	
	// Create a window
	SDL_Window *window = SDL_CreateWindow("Particle Fire Exploration", 
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
	SDL_WINDOW_SHOWN);
	
	// Check if process failed
	if (window == NULL) {
		cout << "Could not create window: %s\n" << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}
	
	/* 
		Update particles 
		Draw particles
		Check for messages/events
	*/
	bool quit = false;
	SDL_Event event;
	while (!quit) {	
		// Fetch the latest event and fill info about recent events into event
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
