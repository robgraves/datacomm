#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

///////////////////////////////////////////////////////////////
// Weapon types, or an ammo type.
// What are you firing, not how are you firing.

#define BULLET   0x0000 // Bullet single target damamge
#define MISSILE  0x0001 // Missile (bullet with AOE explotion)
#define LAZER    0x0002 // Similar to bullet 
//#define FIRE     0x0004 // 

//////////////////////////////////////////////////////////////
// Weapon firing type.
// How are you firing the weapon.

#define NORMAL   0x0100 // Single shot constant speed
#define BURST    0x0200 // Multiple shots in a single direction
#define TRIPPLE  0x0400 // Typical shotgun effect
#define MEGA     0x0800 // Multiple shots side by side in a single direction

 Player : public Entity {
	public:
		void HelloWorld();
	private:
        short int weapon;
		
};
