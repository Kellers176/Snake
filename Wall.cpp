#include "Wall.h"

Wall::Wall()
{
	mPosY = 0;
	mPosX = 0;
}

Wall::Wall(int myX, int myY, Sprite mySprite)
{
	mPosX = myX;
	mPosY = myY;
	mCurrentSprite = mySprite;

}

Wall::~Wall()
{
}

void Wall::drawMyWall()
{
	mCurrentSprite.getGraphicsBuffer()->drawBitmap(mPosX, mPosY);
}

int Wall::getPosX()
{
	return mPosX;
}

int Wall::getPosY()
{
	return mPosY;
}
