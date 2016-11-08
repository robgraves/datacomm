// Standard Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// SDL Includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// TheGame Includes
#include "inc/render.h"
#include "inc/player.h"

// Global Variables
int SCREEN_WIDTH;
int SCREEN_HEIGHT;

SDL_Window *window;
SDL_Surface *surface;
Entity *player;

SDL_Event e;
Uint8 *keystate;

Entity *initial;
Entity *closing;

// Function prototypes
void init();
void loop();
void movement();
void paint();

void addEntity(Entity *);
void removeEntity(Entity *);

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
			Entity *bg = new Entity();;
			bg -> setSurface(surface);
			bg -> setBox(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
			bg -> setLayer(0);
			initial = bg;
			closing = bg;

			player = new Entity();
			player -> setSurface(IMG_Load("player.png"));
			player -> setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 36, 58);
			player -> setBox(0,0,36,58);
			addEntity(player);

			keystate = NULL;
		}
	}
}

void loop() {
	while (1) {
		// Logic
		movement();

		// Repaint
		paint();
	}
}

void movement() {
	SDL_PollEvent(&e);
	keystate = (Uint8 *) SDL_GetKeyboardState(NULL);
	SDL_Rect *playerPos = player -> getPos();
	if (keystate[SDL_SCANCODE_UP]) {
		playerPos -> y -= 5;
	}
	if (keystate[SDL_SCANCODE_DOWN]) {
		playerPos -> y += 5;
	}
	if (keystate[SDL_SCANCODE_LEFT]) {
		playerPos -> x -= 5;
	}
	if (keystate[SDL_SCANCODE_RIGHT]) {
		playerPos -> x += 5;
	}
	player -> setPos(*playerPos);
	if (keystate[SDL_SCANCODE_ESCAPE]) {
		SDL_Quit();
		exit(0);
	}
}

void paint() {
	// Repaint everything
	SDL_FillRect(initial -> getSurface(), NULL, SDL_MapRGB((initial -> getSurface()) -> format, 0xFF, 0x00, 0xF0));

	// Paint second entry through last in list based on layer
	Entity *tmp = initial -> getNext();
	while (tmp != NULL) {
		//SDL_Rect *box = &(tmp -> box);
		//SDL_Rect *pos = &(tmp -> pos);
		SDL_BlitSurface(tmp -> getSurface(), tmp -> getBox(), initial -> getSurface(), tmp -> getPos());
		tmp = tmp -> getNext();
	}

	// Update window
	SDL_UpdateWindowSurface(window);	
}

void addEntity(Entity *entity) {
	closing -> setNext(entity);
	closing = entity;
}

void removeEntity(Entity *entity) {
	Entity *tmp = initial;
	while (tmp -> getNext() != entity) {
		tmp = tmp -> getNext();
	}
	tmp -> setNext(entity -> getNext());

	if (closing == entity) {
		closing = tmp;
	}
}
