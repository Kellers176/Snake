#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Event.h"
#include "EventSystem.h"
#include "allegro5\allegro.h"



class InputSystem: public Trackable
{


public:
	InputSystem();
	~InputSystem();

	void initInputSystem();
	void cleanupInputSystem();

	void updateInputSystem(double dt);

	void updateKeyboard();



private:
	Event mSystemEvent;

	ALLEGRO_EVENT_QUEUE* mKeyboardEventQueue;
	ALLEGRO_EVENT mEvent;


	

};