#pragma once
#include "Trackable.h"
#include "Sprite.h"
#include "Animation.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

enum PowerUpType
{
	POINT_BOOST,
	SLOW_SNAKE_DOWN,
	SPEED_SNAKE_UP,
	END
};


class PowerUp : public Trackable
{
public:
	PowerUp();
	PowerUp(PowerUpType myType, GraphicsBuffer myBuffer, int myX, int myY, int length, int rows, int cols);
	~PowerUp();

	void setTypeOfPowerUp(PowerUpType myType);
	void drawMyPowerUp();
	PowerUpType getType();
	void update(int deltaTime);

	void resetType();
	int getPosX();
	int getPosY();



private:
	int mPosX;
	int mPosY;
	int mLength;
	PowerUpType mType;
	Animation *mAnimator;

};
