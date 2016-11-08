#ifndef MISSILE_H
#define MISSILE_H

#include "render.h"

class Missile : public Entity {
	public:
/////////////// Setting up missile dimentions (If universal missile sprite is used) //////////////////
		/* This stuff goes in the constructor
		missilebox.x = 0;
		missilebox.y = 0;
		missilebox.w = 16;
		missilebox.h = 16;
		*/
		Entity			*Mstart;
		void Spawn(Entity **, int, int);
		Missile();

	private:
		int			Health;
		Entity			*Mend;
		int			direction;
		int			Speed;
};

#endif
