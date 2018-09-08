#include "PauseEvent.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
PauseEvent::PauseEvent(bool isActive)
	:Event(PAUSE_EVENT)
{
	mSetAnim = isActive;
}

PauseEvent::~PauseEvent()
{
}

bool PauseEvent::getAnim() const
{
	return mSetAnim;
}
