#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"
#include "Font.h"
#include "Color.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <string>


using namespace std;
class GraphicsSystem:public Trackable
{
public:

	GraphicsSystem();
	~GraphicsSystem();

	int initGraphicsSystem();
	void cleanGraphicsSystem();

	void setHeight(int myHeight);
	void setWidth(int myWidth);

	int getHeight();
	int getWidth();
	
	void display(int height, int width);
	void drawSprite(int locationX, int locationY, GraphicsBuffer& mySprite, float widthScale, float heightScale);
	void drawSprite(GraphicsBuffer& myBuffer, int locationX, int locationY, GraphicsBuffer& mySprite, float scale); //draw to graphics buffer
	void drawSprite(int locationX, int locationY, GraphicsBuffer& mySprite);
	void writeText(int locationX, int locationY, Font& myColor, Color& myyColor, string myMessage);
	void writeText(GraphicsBuffer& myBuffer, int locationX, int locationY, Font& myFont, Color& myColor, string myMessage);
	void saveBuffer(string filename, GraphicsBuffer& myBuffer);
	void drawActualSprite(Sprite& sprite, int locationX, int locationY);
	void drawColorBuffer(int r, int g, int b);
	void flipDisplay();
	GraphicsBuffer getBackBuffer();
	void wait();



private:
	int mHeight;
	int mWidth;
	float mScale;
	ALLEGRO_DISPLAY* mDisplay;
	GraphicsBuffer mBuffer;
	const int SLEEP_TIME = 5.0;
	



};