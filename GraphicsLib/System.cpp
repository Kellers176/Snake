#include "System.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
System::System()
{

}

System::~System()
{
	cleanupSystem();
}

int System::initSystem()
{
	if (!al_install_keyboard())
	{
		cout << "Failed to install the keyboard" << endl;
		return 1;
	}
	if (!al_install_mouse())
	{
		cout << "Failed to install the mouse" << endl;
		return 1;
	}
	mSystem.initInputSystem();
	return 0;
}

void System::cleanupSystem()
{

}

bool System::getKeyState(int key)
{
	ALLEGRO_KEYBOARD_STATE keyState;

	al_get_keyboard_state(&keyState);
	return al_key_down(&keyState, key);
	
}


GraphicsSystem System::getGraphicsSystem()
{
	return mGraphicsSystem;
}

InputSystem System::getInputSystem()
{
	return mSystem;
}

ALLEGRO_MOUSE_STATE System::getMouseState()
{
	ALLEGRO_MOUSE_STATE mouseState;
	al_get_mouse_state(&mouseState);
	return mouseState;
}
