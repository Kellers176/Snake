#pragma once
#include "Trackable.h"
#include "Sprite.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class Food : public Trackable
{
public:
	Food();
	Food(Sprite mySprite, int myPosX, int myPosY);
	~Food();

	void drawMyFood(int posX, int posY);
	Sprite getCurrentSprite();

	int getFoodLocX();
	int getFoodLocY();

private:
	int mPosX;
	int mPosY;
	Sprite mCurrentSprite;


};
