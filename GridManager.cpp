#include "GridManager.h"

GridManager::GridManager()
{
	mWidth = 0;
	mHeight = 0;
	mSpriteLength = 0;
}

GridManager::GridManager(Sprite mySprite, int myHeight, int myWidth, int mySpriteLength)
{
	mWidth = myWidth;
	mHeight = myHeight;
	mSpriteLength = mySpriteLength;
	mGrideArraySprite = mySprite;

	mIndex = 0;
	mGrid = new Grid[mHeight * mWidth];

	for(int i = 0; i < mWidth; i++)
		for (int j = 0; j < mHeight; j++)
		{
			mIndex = (j * mWidth) + i;
			mGrid[mIndex] = Grid(mGrideArraySprite, i * mSpriteLength, j * mSpriteLength);
		}
	
}

GridManager::~GridManager()
{
	cleanupGridManager();
}

void GridManager::drawMyGrid()
{
	int length = mWidth * mHeight;
	for (int i = 0; i < length; i++)
	{
		mGrid[i].drawGridTile();
	}
}

Grid * GridManager::getGrid()
{
	return mGrid;
}

void GridManager::cleanupGridManager()
{
	delete[] mGrid;
}
