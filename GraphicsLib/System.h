#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "InputSystem.h"
#include "GraphicsSystem.h"
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>

class System : public Trackable
{
	friend class Game;
	friend class LevelManager;
public:
	System();
	~System();

	//install keyboard and mouse
	int initSystem();
	void cleanupSystem();
	bool getKeyState(int key);
	GraphicsSystem getGraphicsSystem();
	InputSystem getInputSystem();



private:
	ALLEGRO_MOUSE_STATE getMouseState();
	GraphicsSystem mGraphicsSystem;
	InputSystem mSystem;



};
