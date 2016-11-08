#include "inc/entity.h"

/* Entity Constructor */
Entity :: Entity() {
	surface = NULL;
	layer 	= -1;
	next 		= NULL;
}

/* Getters */
int	Entity :: getX() {
		return x;
}

int Entity :: getY() {
		return y;
}

SDL_Surface* Entity :: getSurface() {
	return surface;
}

SDL_Rect* Entity :: getBox() {
	return &box;
}

SDL_Rect* Entity :: getPos() {
	return &pos;
}

Entity* Entity :: getNext() {
	return next;
}

int	Entity :: getLayer() {
	return layer;
}

/* Setters */

void Entity :: setX(int x) {
    this -> x = x;
}

void Entity::setY(int y) {
    this -> y = y;
}

void Entity :: setHP(int hp) {
    this -> hp = hp;
}

void Entity :: setMag(int mag) {
    this -> mag = mag;
}

void Entity :: setDir(int dir) {
    this -> dir = dir;
}

void Entity :: setSurface(SDL_Surface *surface) {
	this -> surface = surface;
}

void Entity :: setBox(SDL_Rect box) {
	this -> box = box;
}

void Entity :: setBox(int x, int y, int w, int h) {
	this -> box.x = x;
	this -> box.y = y;
	this -> box.w = w;
	this -> box.h = h;
}

void Entity :: setPos(SDL_Rect pos) {
	this -> pos = pos;
}

void Entity :: setPos(int x, int y, int w, int h) {	
	this -> pos.x = x;
	this -> pos.y = y;
	this -> pos.w = w;
	this -> pos.h = h;
}

void Entity :: setNext(Entity *next) {
	this -> next = next;
}

void Entity :: setLayer(int layer) {
	this -> layer = layer;
}

