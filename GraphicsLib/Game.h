#pragma once
#include "Trackable.h"
#include "System.h"

class Game :public Trackable
{
public:
	Game();
	~Game();

	void initGame();
	void cleanupGame();

	void DoLoop(); //Get user input, adjust the game state(based on user input and other automatic factors), draw the current game state
	//i think i need to add more to this but i am not sure


private:
	System mSystem;




};


