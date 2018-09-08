#include "WallManager.h"

WallManager::WallManager()
{
}

WallManager::WallManager(Sprite mySprite, int mywidth, int myHeight, int myLength)
{
	mWidth = mywidth;
	mHeight = myHeight;
	mCurrentWallSprite = mySprite;
	mLength = myLength;
	int count = 0;
	mArrayLength = (mWidth * 2) + ((mHeight - 2) * 2);
	mWall = new Wall[mArrayLength];

	//sets the height walls
	for (int i = 1; i < mHeight - 1; i++)
	{
		mWall[count] = Wall(0, i * mLength, mCurrentWallSprite);
		count++;
	}
	for (int i = 1; i < mHeight - 1; i++)
	{
		mWall[count] = Wall(mLength * (mWidth - 1), i * mLength, mCurrentWallSprite);
		count++;
	}
	//sets the width walls
	for (int i = 0; i < mWidth; i++)
	{
		mWall[count] = Wall(i * mLength, 0, mCurrentWallSprite);
		count++;
	}
	for (int i = 0; i < mWidth; i++)
	{
		mWall[count] = Wall(i * mLength, mLength * (mHeight - 1), mCurrentWallSprite);
		count++;
	}
}

WallManager::~WallManager()
{
	delete[] mWall;
}

void WallManager::drawMyWallManager()
{
	for (int i = 0; i < mArrayLength; i++)
	{
		mWall[i].drawMyWall();
	}
}

int WallManager::getWallLength()
{
	return mLength;
}

Wall * WallManager::getWall()
{
	return mWall;
}
