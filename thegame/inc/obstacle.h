#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "entity.h"

class Obstacle : public Entity {
	public:
			SDL_Rect getPos();
			void setPos(SDL_Rect);
			void setPos(int x, int y, int w, int h);
	private:
			SDL_Rect		obsBox;
			SDL_Rect		obsPos;
};

#endif
