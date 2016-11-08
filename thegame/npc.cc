#include <stdio.h>
#include "inc/npc.h"
#include "time.h"

// IQ based movement function //
// Create the AI for moving the NPE//

void IQ1move()
{
    /*following the leader
    current and destination = list -> start x or y*/
}

void IQ2move()
{
	/* the leader
	Telling the leader wehre to go*/


    //starting him pointing down
    int npcDir = 1;
    //need pointer
    rtmp = * SDL_Rect;

    while(1)
    {
	//get random number from 1-4
	int z = 0;
	srand(time(NULL));
	z = rand();
	z = (z%4);

	switch(z)
	    {
		//up
		case 0:
		npcDir = 0;
		rtmp = getPos();
		rtmp -> y = rtmp -> y - 1;
		break;

		//down
		case 1:
		npcDir = 1;
		rtmp = getPos();
		rtmp -> y = rtmp -> y + 1;
		break;

		//left
		case 2:
		npcDir = 2;
		rtmp = getPos();
		rtmp -> x = rtmp -> x - 1;
		break;
		
		//right
		case 3:
		npcDir = 3;
		rtmp = getPos();
		rtmp -> x = rtmp -> x + 1;
		break;
	    }
	    //still need to assign accurate npcDir
    }
}

void IQ3move
{
	/* Rogue //
	uses the same movement as the leader
	basic dodgeing emchanics
	abiltiy to target player.x player.y */
}

void IQ4move()
{
	/* Boss
	sliding acros the top of the screen
	stops randomly possibly use time
	when stops fire a lazer strait down
	spawn smaller ones IQ 2 followed by IQ 1*/
}

