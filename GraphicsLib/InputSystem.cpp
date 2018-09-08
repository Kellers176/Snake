/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "InputSystem.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "EscapeEvent.h"
#include "UpArrowEvent.h"
#include "DownArrowEvent.h"
#include "RightArrowEvent.h"
#include "LeftArrowEvent.h"
#include "SpaceBarEvent.h"
#include "allegro5\allegro.h"


InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::initInputSystem()
{
	mKeyboardEventQueue = al_create_event_queue();
	al_register_event_source(mKeyboardEventQueue, al_get_keyboard_event_source());
	al_register_event_source(mKeyboardEventQueue, al_get_mouse_event_source());
	
}

void InputSystem::cleanupInputSystem()
{
}

void InputSystem::updateInputSystem(double dt)
{
	updateKeyboard();
}

void InputSystem::updateKeyboard()
{
	int posX, posY;
	bool myBool = false;
	bool isPressedMouse = false;
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_KEYBOARD_STATE keyState;

	EventSystem* mEventSystem = EventSystem::getInstance();
	ALLEGRO_EVENT ev;

	al_get_keyboard_state(&keyState);
	al_get_mouse_state(&mouseState);


	while (al_get_next_event(mKeyboardEventQueue, &ev))
	{
		//al_get_keyboard_state(&keyState);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			mEventSystem->fireEvent(EscapeEvent(true));
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_UP)
		{
			mEventSystem->fireEvent(UpArrowEvent());
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_DOWN)
		{
			//Not Working
			mEventSystem->fireEvent(DownArrowEvent());
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
		{
			mEventSystem->fireEvent(LeftArrowEvent());
		}

		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
		{
			mEventSystem->fireEvent(RightArrowEvent());
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
		{
			mEventSystem->fireEvent(SpaceBarEvent());
		}

		//al_get_mouse_state(&mouseState);

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button == 1)
		{
			isPressedMouse = false;
			posX = mouseState.x;
			posY = mouseState.y;
			mEventSystem->fireEvent(AddUnitEvent(posX, posY));

		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && ev.mouse.button == 2)
		{
			posX = mouseState.x;
			posY = mouseState.y;
			mEventSystem->fireEvent(DeleteUnitEvent(posX, posY));

		}
	}

	

}

