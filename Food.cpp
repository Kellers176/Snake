#include "Food.h"

Food::Food()
{
	mPosX = 0;
	mPosY = 0;
}

Food::Food(Sprite mySprite, int myPosX, int myPosY)
{
	mCurrentSprite = mySprite;
	mPosX = myPosX;
	mPosY = myPosY;
}

Food::~Food()
{
}

void Food::drawMyFood(int posX, int posY)
{
	mCurrentSprite.getGraphicsBuffer()->drawBitmap(posX, posY);
}

Sprite Food::getCurrentSprite()
{
	return mCurrentSprite;
}

int Food::getFoodLocX()
{
	return mPosX;
}

int Food::getFoodLocY()
{
	return mPosY;
}
