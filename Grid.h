#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Sprite.h"

class Grid : public Trackable
{
public:
	Grid();
	Grid(Sprite mySprite, int myX, int myY);
	~Grid();

	void drawGridTile();
	Sprite getCurrentSprite();

	int getPoxX();
	int getPosY();


private:
	int mPosX;
	int mPosY;
	Sprite mCurrentSprite;
	
};