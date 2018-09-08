#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <string>

using namespace std;

class Font : public Trackable
{

public:
	friend class GraphicsSystem;
	Font();
	Font(int size, string fileName);
	~Font();

	void destroyFont();

	void setSizeOfFont(int mySize);
	int getSizeOfFont();



private:
	int mFontSize;
	ALLEGRO_FONT* mFont;
	string ASSET_PATH = "..\\..\\shared\\assets\\";
	string mFileName;
	ALLEGRO_FONT* getFont();


};
