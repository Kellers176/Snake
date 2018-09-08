#pragma once
#include "Trackable.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
class Level : public Trackable
{
public:
	Level();
	~Level();

	void increaseLevel();
	bool doneLevel();

	void setLevel(int mylevel);

	int getCurrentLevel();


private:
	int mCurrentLevel;

};
