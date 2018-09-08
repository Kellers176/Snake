#include "DeleteUnitEvent.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
DeleteUnitEvent::DeleteUnitEvent(int x, int y)
	:Event(DELETE_UNIT_EVENT)
{
	mPosX = x;
	mPosY = y;
}

DeleteUnitEvent::~DeleteUnitEvent()
{
}

int DeleteUnitEvent::getPosX() const
{
	return mPosX;
}

int DeleteUnitEvent::getPosY() const
{
	return mPosY;
}


