#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Animation.h"
#include <vector>
#include "System.h"
class Unit : public Trackable
{
	friend class Game;
public:
	Unit();
	Unit(Animation* deanAnim, Animation* smurfAnim);
	Unit(string path1, string path2, int sizeX, int sizeY);
	~Unit();

	void updateUnit(double deltaTime);
	void drawCurrentAnimationSprite(System& mThisSystem); //may need to change this to sprite
	void swapAnimation(); //switch to a new animation
	void setPosX(int posX);
	void setPosY(int posY);

	int getX();
	int getY();

	


private:
	//maybe make a pointer
	Animation *mAnimation;
	Animation *mSmurfAnimation, *mDeanAnimation;
	int mPosX;
	int mPosY;
};