#include "inc/utils.h"

/**
 * Check collision between two SDL_Rect objects
 *
 * @param r1 - First rect for collision check
 * @param r2 - Second rect for collision check
 *
 * @return direction of collision relative to r1;
 *		0: NO COLLISION
 *		1: TOP COLLISION
 *		2: BOTTOM COLLISION
 *		3: LEFT COLLISION
 *		4: RIGHT COLLISION
*/
static char collision(SDL_Rect r1, SDL_Rect r2) {
	
	// Top Collision
	if (r1.y <= (r2.y + r2.h) 
		&& (r1.x + r1.w) >= r2.x
		&& r1.x <= (r2.x + r2.w)) {
		if (r1.y < r2.y) {
			return 1;
		}
	}
	
	// Bottom Collision	
	if ((r1.y + r2.h) >= r2.y 
		&& (r1.x + r1.w) >= r2.x
		&& r1.x <= (r2.x + r2.w)) {
		if (r1.y > r2.y) {
			return 2;
		}
	}

	// Left-Collision
	if (r1.x <= (r2.x + r2.w) 
		&& r1.y <= (r2.y + r2.h)
		&& (r1.y + r1.h) >= r2.y) {
		if (r1.x > r2.x) {
			return 3;
		}
	}

	// Right-Collision
	if ((r1.x + r1.w) >= r2.x 
		&& r1.y <= (r2.y + r2.h)
		&& (r1.y + r1.h) >= r2.y) {
		if (r1.x < r2.x) {
			return 4;
		}
	}

	return 0;
}
