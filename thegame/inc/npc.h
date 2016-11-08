#include "entity.h"

class npc : public Entity
{
    public:
            void HelloWorld();
    private:

/* I want to put some kind of code here because we need to create/paint the NPC in general?
**taken form joyfun.c**
NOT MEANT TO BE EXCAT CODE :( - too many questions!*/


/*
surface = SDL_GetWindowSurface(window);
image = SDL_LoadBMP("npc1");
block = SDL_CreateRGBSurface(0, blockbox.w,blockbox.h//..?);

SDL_FillRect(surface, NULL, SDL_MapRGB(surface-> format, 0x00, 0x00, 0x00));

SDL_FillRect(block, NULL, SDL_MapRBG(block -> format, 0xFF, 0xFF, 0xFF));

SDL_Blitsurface(image, &sprite, surface, &box);
blockpos.x = 0;
blockpos.y = 0;
..
..? right track?
*/
};
