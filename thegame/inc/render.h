#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

class Object {
	private:	
		SDL_Surface *surface;
		SDL_Rect 		box;
		SDL_Rect 		pos;
		int 				layer;
		Object 			*next;
	public:	
		Object();
		SDL_Surface *getSurface();
		SDL_Rect		*getBox();
		SDL_Rect		*getPos();
		Object			*getNext();
		int					getLayer();
		void				setSurface(SDL_Surface*);
		void 				setBox(SDL_Rect);
		void 				setPos(SDL_Rect);
		void				setBox(int x, int y, int w, int h);
		void				setPos(int x, int y, int w, int h);
		void				setNext(Object*);
		void				setLayer(int);
};

class ObjectList {
	public:
		ObjectList(Object *);
		void add(Object *);
		void remove(Object *);
		Object *initial;
		Object *closing;
};

#endif
