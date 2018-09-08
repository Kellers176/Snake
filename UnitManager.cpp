/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "UnitManager.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "Event.h"
#include "EventSystem.h"

UnitManager::UnitManager()
{
	//mCurrentIndex = 0;
	mShouldAnimate = true;
	/*EventSystem::getInstance()->addListener(ADD_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(DELETE_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(PAUSE_EVENT, this);*/
}

UnitManager::~UnitManager()
{
	clearUnits();
	//EventSystem::getInstance()->removeListener(ADD_UNIT_EVENT, this);
	//EventSystem::getInstance()->removeListener(DELETE_UNIT_EVENT, this);
	//EventSystem::getInstance()->removeListenerFromAllEvents(this);
}

Unit* UnitManager::addUnits(string key, int positionX, int positionY, string filepath1, string filepath2, int sizeX, int sizeY)
{
	Unit* pUnit = NULL;

	//figure out if it exists already
	map<string, Unit*>::iterator iter = mUnits.find(key);

	//already in map?
	if (iter == mUnits.end())
	{
		//not already there - just create and add it
		pUnit = new Unit(filepath1, filepath2, sizeX, sizeY);
		pUnit->setPosX(positionX);
		pUnit->setPosY(positionY);
		mUnits[key] = pUnit;

	}
	return pUnit;
	
}

Unit * UnitManager::addUnits(int positionX, int positionY, string filepath1, string filepath2, int sizeX, int sizeY)
{
	Unit* pUnit = NULL;
	string key = "Unit" + ++mUnitIndex;

	//figure out if it exists already
	map<string, Unit*>::iterator iter = mUnits.find(key);

	//already in map?
	if (iter == mUnits.end())
	{
		//not already there - just create and add it
		pUnit = new Unit(filepath1, filepath2, sizeX, sizeY);
		pUnit->setPosX(positionX);
		pUnit->setPosY(positionY);
		mUnits[key] = pUnit;

	}
	return pUnit;
	
}


void UnitManager::deleteUnits(string key)
{
	//figure out if it exists already
	map<string, Unit*>::iterator iter = mUnits.find(key);

	//already in map?
	if (iter != mUnits.end())
	{
		delete iter->second;
		mUnits.erase(iter);

	}
}

Unit* UnitManager::getUnit(string key)
{
	map<string, Unit*>::const_iterator iter = mUnits.find(key);

	if (iter != mUnits.end())
	{
		return mUnits[key];
	}
	else
	{
		return NULL;
	}
	
}


void UnitManager::clearUnits()
{
	map<string, Unit*>::iterator iter;

	//go through all entries in map and delete
	for (iter = mUnits.begin(); iter != mUnits.end(); ++iter)
	{
		Unit* pUnit = iter->second;
		delete pUnit;
	}

	mUnits.clear();
}

void UnitManager::update(double deltaTime)
{
	if (mShouldAnimate)
	{
		for (map<string, Unit*>::iterator iter = mUnits.begin(); iter != mUnits.end(); iter++)
		{
			if (iter->second)
			{
				iter->second->updateUnit(deltaTime);
			}
		}

	}
}

void UnitManager::draw(System& mySystem)
{
	for (map<string, Unit*>::iterator iter = mUnits.begin(); iter != mUnits.end(); iter++)
	{
		if (iter->second)
		{
			iter->second->drawCurrentAnimationSprite(mySystem);
		}
	}
}

void UnitManager::checkWhichUnitIsClicked(int x, int y, int sizeX, int sizeY)
{
	for (std::map<string, Unit*>::iterator iter = mUnits.begin(); iter != mUnits.end(); iter++)
	{
		if (iter->second)
		{
			//check to see if clicked within units
			if ((x < iter->second->getX() + sizeX && x >= iter->second->getX()) && (y < (iter->second->getY() + sizeY) && y >= iter->second->getY()))
			{
				deleteUnits(iter->first);
				break;
			}
		}
	}
}

int UnitManager::getCurrentIndex()
{
	return mUnitIndex;
}

void UnitManager::setAnimation(bool myBool)
{
	mShouldAnimate = myBool;
}

bool UnitManager::getAnimation()
{
	return mShouldAnimate;
}

//void UnitManager::handleEvent(const Event &theEvent)
//{
	/*if (theEvent.getType() == ADD_UNIT_EVENT)
	{
		const AddUnitEvent& addEvent = static_cast<const AddUnitEvent&>(theEvent);
		addUnits(addEvent.getPosX(), addEvent.getPosY(), addEvent.getFilePath1(), addEvent.getFilePath2());

	}
	if (theEvent.getType() == DELETE_UNIT_EVENT)
	{
		const DeleteUnitEvent& deleteEvent = static_cast<const DeleteUnitEvent&>(theEvent);
		checkWhichUnitIsClicked(deleteEvent.getPosX(), deleteEvent.getPosY());

	}
	if (theEvent.getType() == PAUSE_EVENT)
	{
		const PauseEvent& pauseEvent = static_cast<const PauseEvent&>(theEvent);
		setAnimation(pauseEvent.getAnim());
		checkWhichUnitIsClicked(deleteEvent.getPosX(), deleteEvent.getPosY());

	}*/
//}
