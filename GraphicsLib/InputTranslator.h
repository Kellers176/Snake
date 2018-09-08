#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Event.h"
#include "EventListener.h"
#include "EventSystem.h"
#include "../UnitManager.h"



class InputTranslator : public EventListener
{
public:
	//calls the events
	InputTranslator();
	~InputTranslator();

	void initInputTranslator();
	void cleanupInputTranslator();

	void handleEvent(const Event &theEvent);

	void updateInputTranslator(double dt);


private:
	UnitManager* mManager;
	const string mASSET_PATH = "..\\..\\shared\\assets\\";
	const string mOTHER_BACKGROUND_FILENAME = "Woods.png";
	const string mSMURF_FILE = "smurf_sprites.png";
	const string mDEAN_FILE = "dean_sprites.png";
};
