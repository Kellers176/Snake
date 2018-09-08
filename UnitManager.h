#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Unit.h"
#include "System.h"
#include "EventListener.h"
#include <map>


using namespace std;

class UnitManager : public Trackable
{
	friend class Game;
public:
	UnitManager();
	~UnitManager();

	Unit* addUnits(string key, int positionX, int positionY, string filepath1, string filepath2, int sizeX, int sizeY);
	Unit* addUnits(int positionX, int positionY, string filepath1, string filepath2, int sizeX, int sizeY);
	void deleteUnits(string key);
	Unit* getUnit(string key);
	void clearUnits(); //remove and delete all units
	void update(double deltaTime);
	void draw(System& mySystem);
	void checkWhichUnitIsClicked(int x, int y, int sizeX, int sizeY);

	int getCurrentIndex();
	void setAnimation(bool myBool);
	bool getAnimation();

	/*void handleEvent(const Event &theEvent);*/



private:
	map<string, Unit*> mUnits;
	int mUnitIndex;
	System mSystem;
	bool mShouldAnimate;

};