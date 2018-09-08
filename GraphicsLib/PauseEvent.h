#pragma once
#include "Event.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class PauseEvent : public Event
{
public:
	PauseEvent(bool isActive);
	~PauseEvent();

	bool getAnim() const;



private:
	bool mSetAnim;


};
