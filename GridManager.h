#pragma once
#include "Grid.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class GridManager : public Trackable
{
public:
	GridManager();
	GridManager(Sprite mySprite, int myHeight, int myWidth, int mySpriteLength);
	~GridManager();

	void drawMyGrid();
	Grid* getGrid();

	void cleanupGridManager();

private:
	int mHeight;
	int mWidth;
	int mSpriteLength;
	Grid* mGrid;
	Sprite mGrideArraySprite;
	int mIndex;
	

};