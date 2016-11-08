#ifndef MISSILE_H
#define MISSILE_H

#include "render.h"

class Missile : public Object 
{
	public:
/////////////// Setting up missile dimentions (If universal missile sprite is used) //////////////////
		/* This stuff goes in the constructor
		missilebox.x = 0;
		missilebox.y = 0;
		missilebox.w = 16;
		missilebox.h = 16;
		*/
		void Spawn(Missile **, SDL_Rect, SDL_Rect, int, int, int);
		Missile();
	
	private:
		int			direction;
		int			speed;
};

#endif
