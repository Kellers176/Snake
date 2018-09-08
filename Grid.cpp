#include "Grid.h"

Grid::Grid()
{
	mPosX = 0;
	mPosY = 0;
}

Grid::Grid(Sprite mySprite, int myX, int myY)
{
	mCurrentSprite = mySprite;
	mPosX = myX;
	mPosY = myY;
}

Grid::~Grid()
{
}

void Grid::drawGridTile()
{
	mCurrentSprite.getGraphicsBuffer()->drawBitmap(mPosX, mPosY);
}

Sprite Grid::getCurrentSprite()
{
	return mCurrentSprite;
}

int Grid::getPoxX()
{
	return mPosX;
}

int Grid::getPosY()
{
	return mPosY;
}
