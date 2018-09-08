#pragma once
#include "Event.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class InstantiateEvent : public Event
{
public:
	InstantiateEvent(int myX, int myY);
	~InstantiateEvent();

	int getX() const;
	int getY() const;

private:
	int mX;
	int mY;
};