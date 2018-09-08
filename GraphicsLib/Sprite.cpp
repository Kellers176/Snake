/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Sprite.h"

Sprite::Sprite()
{
	mLocationOfSpriteX  = 0;
	mLocationOfSpriteY = 0;
	mHeightOfSprite = 10;
	mWidthOfSprite = 10;
	mFilename = "";

}

Sprite::Sprite(int height, int width, int locX, int locY, GraphicsBuffer* bitmap)
{
	mHeightOfSprite = height;
	mWidthOfSprite = width;
	mLocationOfSpriteX = locX;
	mLocationOfSpriteY = locY;
	mBuffer = bitmap;
}

Sprite::Sprite(int height, int width, int locX, int locY, GraphicsBuffer bitmap)
{
	mSecondBuffer = bitmap;
	mHeightOfSprite = height;
	mWidthOfSprite = width;
	mLocationOfSpriteX = locX;
	mLocationOfSpriteY = locY;
}



Sprite::~Sprite()
{
	
}

void Sprite::setLocationOfSpriteX(int x)
{
	mLocationOfSpriteX = x;
}

void Sprite::setLocationOfSpriteY(int y)
{
	mLocationOfSpriteY = y;
}

void Sprite::setWidthOfSprite(int x)
{
	mWidthOfSprite = x;
}
          
void Sprite::setHeightOfSprite(int y)
{
	mHeightOfSprite = y;
}

void Sprite::setGraphicsBuffer(GraphicsBuffer* buffer)
{
	mBuffer = buffer;
}

int Sprite::getLocationOfSpriteX()
{
	return mLocationOfSpriteX;
}

int Sprite::getLocationOfSpriteY()
{
	return mLocationOfSpriteY;
}

int Sprite::getWidthOfSprite()
{
	return mWidthOfSprite;
}

int Sprite::getHeightOfSprite()
{
	return mHeightOfSprite;
}

GraphicsBuffer*  Sprite::getGraphicsBuffer()
{
	return mBuffer;
}

GraphicsBuffer Sprite::getBitmap()
{
	return mSecondBuffer;
}


