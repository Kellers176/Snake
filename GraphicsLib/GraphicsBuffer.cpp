/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "GraphicsBuffer.h"

GraphicsBuffer::GraphicsBuffer()
{
	mHeight = 600;
	mWidth = 800;
}

GraphicsBuffer::GraphicsBuffer(int myWidth, int myHeight)
{
	//also the same as createBitmap
	mWidth = myWidth;
	mHeight = myHeight;
	mBitmap = al_create_bitmap(mWidth, mHeight);
}

GraphicsBuffer::GraphicsBuffer(string myFile, string myOtherString)
{
	mBitmapFileName = myFile + myOtherString;

	//this line causes error
	mBitmap = al_load_bitmap(mBitmapFileName.c_str());

	mHeight = al_get_bitmap_width(mBitmap);
	mWidth = al_get_bitmap_height(mBitmap);

}

GraphicsBuffer::GraphicsBuffer(string myFile)
{
	mBitmap = al_load_bitmap(myFile.c_str());
	mHeight = al_get_bitmap_width(mBitmap);
	mWidth = al_get_bitmap_height(mBitmap);
}



GraphicsBuffer::~GraphicsBuffer()
{
	//destroyBitmap();
}

void GraphicsBuffer::setHeight(int myHeight)
{
	mHeight = myHeight;
}

void GraphicsBuffer::setWidth(int myWidth)
{
	mWidth = myWidth;
}

void GraphicsBuffer::createBitmap(int width, int height)
{
	//alsoo the same as GraphicsBuffer(int myWidth, int myHeight)
	mBitmap = al_create_bitmap(width, height);
	
}

void GraphicsBuffer::setObjectBitmap(ALLEGRO_BITMAP* myBitmap)
{
	mBitmap = myBitmap;
}

void GraphicsBuffer::setBitmapFileName(string myFile)
{
	mBitmapFileName = myFile;
}

void GraphicsBuffer::color(Color myColor)
{
	al_clear_to_color(myColor.getAllegroColor());
}

ALLEGRO_BITMAP* GraphicsBuffer::getBitmap()
{
	return mBitmap;
}

int GraphicsBuffer::getHeight()
{
	return mHeight;
}

int GraphicsBuffer::getWidth()
{
	 return mWidth;
}

string GraphicsBuffer::getmBitmapFileName()
{
	return mBitmapFileName;
}

void GraphicsBuffer::destroyBitmap()
{
	al_destroy_bitmap(mBitmap);
}

void GraphicsBuffer::drawBitmap(int myX, int myY)
{
	al_draw_bitmap(mBitmap, myX, myY, 0);
}







