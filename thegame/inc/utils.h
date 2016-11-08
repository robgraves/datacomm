#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#ifndef ENTITY_H
#define ENTITY_H

#define NO_C  0x0000
#define UP    0x0001
#define DOWN  0x0010
#define LEFT  0x0011
#define RIGHT 0x0100

class Utils {
	public:
		static char collides(SDL_Rect, SDL_Rect);

	private:
		Utils() {}
		
};

#endif
