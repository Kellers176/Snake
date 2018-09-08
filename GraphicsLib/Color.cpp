/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Color.h"

Color::Color()
{
	mR = 0;
	mG = 0;
	mB = 0;
	mColor = al_map_rgb(mR, mG, mB);
}

Color::~Color()
{
}

void Color::setColor(int myR, int myG, int myB)
{
	mColor = al_map_rgb(myR, myG, myB);
}


ALLEGRO_COLOR Color::getAllegroColor()
{
	return mColor;
}
