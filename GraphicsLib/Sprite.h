#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "GraphicsBuffer.h"
#include <string>

using namespace std;

class Sprite : public Trackable
{
public:

	Sprite();
	Sprite(int height, int width, int locX, int locY, GraphicsBuffer* bitmap);
	Sprite(int height, int width, int locX, int locY, GraphicsBuffer bitmap);
	~Sprite();

	void setLocationOfSpriteX(int x);
	void setLocationOfSpriteY(int y);
	void setWidthOfSprite(int x);
	void setHeightOfSprite(int y);
	void setGraphicsBuffer(GraphicsBuffer* buffer);


	int getLocationOfSpriteX();
	int getLocationOfSpriteY();
	int getWidthOfSprite();
	int getHeightOfSprite();

	GraphicsBuffer* getGraphicsBuffer();
	GraphicsBuffer getBitmap();


private:
	GraphicsBuffer* mBuffer;
	GraphicsBuffer mSecondBuffer;
	int mLocationOfSpriteX;
	int mLocationOfSpriteY;
	int mHeightOfSprite;
	int mWidthOfSprite;
	string mFilename;




};