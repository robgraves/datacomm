#include "inc/render.h"

// Object Constructor
Object :: Object() {
	surface = NULL;
	layer 	= -1;
	next 		= NULL;
}

/* Getters */
SDL_Surface* Object :: getSurface() {
	return surface;
}

SDL_Rect* Object :: getBox() {
	return &box;
}

SDL_Rect* Object :: getPos() {
	return &pos;
}

Object* Object :: getNext() {
	return next;
}

int	Object :: getLayer() {
	return layer;
}

/* Setters */

void Object :: setSurface(SDL_Surface *surface) {
	this -> surface = surface;
}

void Object :: setBox(SDL_Rect box) {
	this -> box = box;
}

void Object :: setBox(int x, int y, int w, int h) {
	this -> box.x = x;
	this -> box.y = y;
	this -> box.w = w;
	this -> box.h = h;
}

void Object :: setPos(SDL_Rect pos) {
	this -> pos = pos;
}

void Object :: setPos(int x, int y, int w, int h) {	
	this -> pos.x = x;
	this -> pos.y = y;
	this -> pos.w = w;
	this -> pos.h = h;
}

void Object :: setNext(Object *next) {
	this -> next = next;
}

void Object :: setLayer(int layer) {
	this -> layer = layer;
}

// ObjectList
ObjectList :: ObjectList(Object *start) {
	initial = start;
	closing = start;
}

void ObjectList :: add (Object *object) {
	closing -> setNext(object);
	closing = object;
}

void ObjectList :: remove (Object *object) {
	Object *tmp = initial;
	while (tmp -> getNext() != object) {
		tmp = tmp -> getNext();
	}
	tmp -> setNext(object -> getNext());

	if (closing == object) {
		closing = tmp;
	}
}
