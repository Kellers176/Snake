#include "Unit.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
Unit::Unit()
{

}

Unit::Unit(Animation* deanAnim, Animation* smurfAnim)
{
	mDeanAnimation = deanAnim;
	mSmurfAnimation = smurfAnim;
}

Unit::Unit(string path1, string path2, int sizeX, int sizeY)
{
	mSmurfAnimation = new Animation();
	mDeanAnimation = new Animation();
	mSmurfAnimation->addSpritesByFileName(path1, sizeX, sizeY);
	mDeanAnimation->addSpritesByFileName(path2, sizeX, sizeY);
	mAnimation = mSmurfAnimation;
}

Unit::~Unit()
{
	delete mSmurfAnimation;
	mSmurfAnimation = NULL;
	delete mDeanAnimation;
	mDeanAnimation = NULL;
}

void Unit::updateUnit(double deltaTime)
{
	mAnimation->update(deltaTime);
}

void Unit::drawCurrentAnimationSprite(System& mThisSystem)
{
	mThisSystem.getGraphicsSystem().drawActualSprite(*mAnimation->getCurrentSprite(), mPosX, mPosY);
}

void Unit::swapAnimation()
{
	if (mAnimation == mSmurfAnimation)
	{
		mAnimation = mDeanAnimation;
	}
	else
	{
		mAnimation = mSmurfAnimation;
	}
}

void Unit::setPosX(int posX)
{
	mPosX = posX;
}

void Unit::setPosY(int posY)
{
	mPosY = posY;
}

int Unit::getX()
{
	return mPosX;
}

int Unit::getY()
{
	return mPosY;
}
