#ifndef ENTITY_H
#define ENTITY_H

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

#include <SDL2/SDL.h>

class Entity {
    private:
				SDL_Surface   *surface;
				SDL_Rect 		  box;
				SDL_Rect 		  pos;
				int 				  layer;
				Entity 			  *next;
        int  					x;
        int  					y;
        int  					hp;
        int  					mag;
        int  					dir;
    public:
				Entity();
				int 					getX();
        int 					getY();
				int						getHP();
				int						getMag();
				int						getDir();
				SDL_Surface	  *getSurface();
				SDL_Rect			*getBox();
				SDL_Rect			*getPos();
				Entity				*getNext();
				int				  	getLayer();
				void			 		setSurface(SDL_Surface*);
				void 			  	setBox(SDL_Rect);
				void 			  	setPos(SDL_Rect);
				void			  	setBox(int x, int y, int w, int h);
				void			  	setPos(int x, int y, int w, int h);
				void			  	setNext(Entity*);
				void			  	setLayer(int);
        void 					setX(int);
        void 					setY(int);
				void					setHP(int);
				void					setMag(int);
				void					setDir(int);
};

#endif
