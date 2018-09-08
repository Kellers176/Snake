/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Font.h"

Font::Font()
{
	mFontSize = 10;
	
}

Font::Font(int size, string fileName)
{
	mFileName = fileName;
	mFontSize = size;
	mFont = al_load_ttf_font(fileName.c_str(), mFontSize, 0);
	if (mFont != NULL)
	{
		assert(mFont);
	}
	else
	{
		cout << "This isnt working" << endl;
	}
}


Font::~Font()
{
	destroyFont();
}

void Font::destroyFont()
{
	al_destroy_font(mFont);
}

void Font::setSizeOfFont(int mySize)
{
	mFontSize = mySize;
}

ALLEGRO_FONT * Font::getFont()
{
	return mFont;
}

int Font::getSizeOfFont()
{
	return mFontSize;
}




