#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Event.h"


class DeleteUnitEvent : public Event
{
public:
	DeleteUnitEvent(int x, int y);
	~DeleteUnitEvent();

	int getPosY() const;
	int getPosX() const;


private:
	int mPosX;
	int mPosY;

};