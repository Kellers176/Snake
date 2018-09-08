#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Sprite.h"
#include "Wall.h"
class WallManager : public Trackable
{
public:
	WallManager();
	WallManager(Sprite mySprite, int mywidth, int myHeight, int myLength);
	~WallManager();

	void drawMyWallManager();
	int getWallLength();
	Wall *getWall();

private:
	int mLength;
	int mWidth;
	int mArrayLength;
	int mHeight;
	Wall * mWall;
	Sprite mCurrentWallSprite;
};
