#pragma once
#include "Trackable.h"
#include "Sprite.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class Wall : public Trackable
{
public:
	Wall();
	Wall(int myWidth, int myHeight, Sprite mySprite);
	~Wall();

	void drawMyWall();
	int getPosX();
	int getPosY();
private:
	int mPosY;
	int mPosX;
	Sprite mCurrentSprite;
};
