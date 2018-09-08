#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Color.h"
#include <allegro5/allegro.h>
#include "Font.h"
#include <string>

using namespace std;

class GraphicsBuffer :public Trackable
{
public:
	friend class GraphicsSystem;
	friend class Game;
	GraphicsBuffer();
	GraphicsBuffer(int myWidth, int myHeight);
	GraphicsBuffer(string myFile, string myOtherString);
	GraphicsBuffer(string myFile);
	~GraphicsBuffer();

	void setHeight(int myHeight);
	void setWidth(int myWidth);
	void createBitmap(int width, int height);
	void setObjectBitmap(ALLEGRO_BITMAP* myBitmap);
	void setBitmapFileName(string myFile);
	void color(Color myColor);
	


	int getHeight();
	int getWidth();
	string getmBitmapFileName();

	void destroyBitmap();
	void drawBitmap(int myX, int myY);





private:
	//dont know if i need this
	ALLEGRO_BITMAP* mBitmap;
	string mBitmapFileName;
	ALLEGRO_BITMAP* getBitmap();
	//GraphicsBuffer* mBuffer;
	int mHeight;
	int mWidth;
	friend class Animation;
};
