#include "InstantiateEvent.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
InstantiateEvent::InstantiateEvent(int myX, int myY)
	:Event(CREATE_UNIT_EVENT)
{
	mX = myX;
	mY = myY;
}

InstantiateEvent::~InstantiateEvent()
{
}
