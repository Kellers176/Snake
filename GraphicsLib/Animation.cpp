#include "Animation.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

Animation::Animation()
{
	mCurrentIndex = 0;
	mCurrentFrameTime = 0;
}

Animation::Animation(int myInt, bool myBool)
{
	mCurrentIndex = 0;
	mArrayLength = myInt;
	mArray = new Sprite[mArrayLength];
	mLoop = myBool;
}


Animation::~Animation()
{
	for (int i = 0; i < mSprites.size(); i++)
	{
		delete mSprites[i];
	}
	mSprites.clear();
	delete mBuffer;
	mBuffer = NULL;
	delete[] mArray;
}

void Animation::addSprite(Sprite* thisSprite)
{
	mSprites.push_back(thisSprite);
}

void Animation::addSecondSprite(Sprite newSprite)
{
	mArray[mCurrentIndex] = newSprite;
	mCurrentIndex++;
}

void Animation::addSpritesByFileName(string assetPath, int sizeX, int sizeY)
{
	int x = 0, y = 0;
	mBuffer = new GraphicsBuffer(assetPath);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Sprite* tmp = new Sprite(sizeX, sizeY, x, y, mBuffer);
			mSprites.push_back(tmp);
			x += sizeX;
		}
		x = 0;
		y += sizeY;
	}
}


void Animation::update(double deltaTime)
{
	if(mTimer.getElapsedTime() > 200.0)
	{
		mCurrentIndex++;
		if(mCurrentIndex >= mArrayLength)
		{
			mCurrentIndex = 0;
		}
		/*mCurrentFrameTime += deltaTime;
		if (mCurrentFrameTime > 1.0 / FPS)
		{
			mCurrentIndex++;
			if (mCurrentIndex >= mArrayLength)
			{
				mCurrentIndex = 0;
			}
		}*/
		mCurrentSprite = mArray[mCurrentIndex];
		mTimer.start();
	}

}

Sprite* Animation::getCurrentSprite()
{
	return mSprites.at(mCurrentIndex);
}

void Animation::speedUpAnimation()
{
	mAnimationTimer.start();


	mAnimationTimer.sleepUntilElapsed(10.0);

}

void Animation::slowDownAnimation()
{
	mAnimationTimer.start();


	mAnimationTimer.sleepUntilElapsed(30);
	
}


int Animation::getCurrentIndex()
{
	return mCurrentIndex;
}

void Animation::drawSprites(int x, int y, int length)
{
	al_draw_bitmap_region(mCurrentSprite.getBitmap().mBitmap, mCurrentSprite.getLocationOfSpriteX(), mCurrentSprite.getLocationOfSpriteY(), length, length, x, y, 0);
}

void Animation::splitSheet(GraphicsBuffer myBuffer, int size, int row, int col)
{
	int x = 0, y = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sprite mySprite(myBuffer.getHeight(), myBuffer.getWidth(), x, y, myBuffer);
			addSecondSprite(mySprite);
			x += size;
		}
		x = 0;
		y += size;
	}
	mCurrentSprite = mArray[0];


}

void Animation::setFrames(int myFrames)
{
	FPS = myFrames;
}
