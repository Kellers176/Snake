#include "PowerUp.h"

PowerUp::PowerUp()
{
	mPosX = 0;
	mPosY = 0;
	mType = END;
}

PowerUp::PowerUp(PowerUpType myType, GraphicsBuffer myBuffer, int myX, int myY, int length, int rows, int cols)
{
	mType = myType;
	mPosX = myX;
	mPosY = myY;
	mAnimator = new Animation(rows*cols, true);
	mAnimator->splitSheet(myBuffer, length, rows, cols);
}

PowerUp::~PowerUp()
{
	delete mAnimator;
}

void PowerUp::setTypeOfPowerUp(PowerUpType myType)
{
	mType = myType;
}

void PowerUp::drawMyPowerUp()
{
	mAnimator->drawSprites(mPosX, mPosY, 40);
	//mCurrentSprite.getGraphicsBuffer()->drawBitmap(mPosX, mPosY);
}

PowerUpType PowerUp::getType()
{
	return mType;
}

void PowerUp::update(int deltaTime)
{
	mAnimator->update(deltaTime);
}

void PowerUp::resetType()
{
	mType = END;
}

int PowerUp::getPosX()
{
	return mPosX;
}

int PowerUp::getPosY()
{
	return mPosY;
}
