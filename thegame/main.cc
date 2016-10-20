// Standard Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SDL Includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// TheGame Includes
#include "inc/player.h"

// Global Variables
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

SDL_Window *window;
SDL_Surface *surface;

// Function prototypes
void init();
void loop();
void paint();

int main() {
	init();
	loop();
	return 0;
}

void init() {
	// Init SDL
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;

	window = NULL;
	surface = NULL;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "SDL could not initialize! ");
		fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(1);
	}
	else {
		window = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			fprintf(stderr, "Window could not be created! ");
			fprintf(stderr, "SDL_Error: %s\n", SDL_GetError());
			SDL_Quit();
			exit(2);
		}
		else {
			surface = SDL_GetWindowSurface(window);
		}
	}
}

void loop() {
	while (1) {
		// Logic

		// Repaint
		paint();
	}
}

void paint() {
	// Repaint everything
	SDL_FillRect(surface, NULL, SDL_MapRGB(surface -> format, 0xFF, 0x00, 0xF0));
	// Update window
	SDL_UpdateWindowSurface(window);	
}
