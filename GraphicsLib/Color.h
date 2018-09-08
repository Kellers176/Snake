#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include <allegro5/allegro.h>

class Color : public Trackable
{
public:
	friend class GraphicsSystem;
	friend class GraphicsBuffer;
	Color();
	~Color();

	void setColor(int myR, int myG, int myB);






private:
	int mR;
	int mG;
	int mB;
	ALLEGRO_COLOR getAllegroColor();
	ALLEGRO_COLOR mColor;





};