#include "AddUnitEvent.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
AddUnitEvent::AddUnitEvent(int posX, int posY)
	:Event(ADD_UNIT_EVENT)
{
	mPosX = posX;
	mPosY = posY;
}

AddUnitEvent::~AddUnitEvent()
{
}

void AddUnitEvent::setPosX(int x)
{
	mPosX = x;
}

void AddUnitEvent::setPosY(int y)
{
	mPosY = y;
}

void AddUnitEvent::setFilePath1(string file)
{
	mFilepath1 = file;
}

void AddUnitEvent::setFilePath2(string file)
{
	mFilepath2 = file;
}

int AddUnitEvent::getPosX() const
{
	return mPosX;
}

int AddUnitEvent::getPosY() const
{
	return mPosY;
}

string AddUnitEvent::getFilePath1() const
{
	return mFilepath1;
}

string AddUnitEvent::getFilePath2() const
{
	return mFilepath2;
}
