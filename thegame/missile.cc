#include "inc/missile.h"


/*void Missile :: Spawn (Missile **Mstart, SDL_Rect PlayerPos, SDL_Rect PlayerBox, int PlayerDir, int Velocity, int Health) { // Makes the missile initial pointer the return
	Missile *Mend = NULL;
	if ( (*Mstart) == NULL ) { // No projectiles created yet
		*Mstart = (Missile *) malloc (sizeof(Missile));
		(*Mstart) -> surface = missile; // Assuming missile is the surface for the projectiles & all projectiles have the same texture && this is a public variable name
		(*Mstart) -> box = missilebox;
		(*Mstart) -> pos = missilepos;
		(*Mstart) -> next = NULL; // Only 1 in list, so next points to nothing
		Mend = Mstart;
	} else { // Some projectile(s) exist currently
		Mend = Mstart;
		while (Mend -> next != NULL) { // Puts Mend at end of list
			Mend = Mend -> there;
		}
		Mend -> next = (Missile *) malloc (sizeof(Missile));
		Mend = Mend -> next; // Allocated space for next node and shifted to it
		Mend -> surface = missile; // Again, all assumptions for previos surface set stand here
		Mend -> box = missilebox;
		Mend -> pos = missilepos;
		Mend -> next = NULL;
	}
	Mend -> pos.x = PlayerPos.x + (PlayerBox.w/2)-(Mend -> box.w/2); // Sets x spawn coordinates for current projectile
	Mend -> pos.y = PlayerPos.y + (PlayerBox.h/2)-(Mend -> box.h/2); // Sets y spawn coordinates for current projectile
	Mend -> MisDir = PlayerDir; // Sets direction of projectile
	Mend -> box.x  = 16 * Mend -> MisDir;
	Mend -> MisSpeed = Velocity // Sets speed and health of each individual missile;
	Mend -> MisHealth = Health;
}*/

