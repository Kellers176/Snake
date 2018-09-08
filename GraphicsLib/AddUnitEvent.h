
#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Event.h"


class AddUnitEvent : public Event
{
public:
	AddUnitEvent(int posX, int posY);
	~AddUnitEvent();

	void setPosX(int x);
	void setPosY(int y);
	void setFilePath1(string file);
	void setFilePath2(string file);
				  
	 int getPosY() const;
	 int getPosX() const;
	string getFilePath1() const;
	string getFilePath2() const;




private:
	int mPosX;
	int mPosY;
	string mFilepath1;
	string mFilepath2;


};