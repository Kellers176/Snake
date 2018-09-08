/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "InputTranslator.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "EscapeEvent.h"
#include "InstantiateEvent.h"
#include "RemoveEvent.h"
#include "TempStopEvent.h"
#include "StopEvent.h"
#include "UpArrowEvent.h"
#include "DownArrowEvent.h"
#include "RightArrowEvent.h"
#include "LeftArrowEvent.h"
#include "SpaceBarEvent.h"
#include "MoveDownEvent.h"
#include "MoveLeftEvent.h"
#include "MoveRightEvent.h"
#include "MoveUpEvent.h"
#include "NextLevelEvent.h"


InputTranslator::InputTranslator()
{
	
}

InputTranslator::~InputTranslator()
{
	cleanupInputTranslator();
}

void InputTranslator::initInputTranslator()
{
	//Game::getInstance()->setDone(escapeEvent.getBool());
	EventSystem::getInstance()->addListener(ADD_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(DELETE_UNIT_EVENT, this);
	EventSystem::getInstance()->addListener(PAUSE_EVENT, this);
	EventSystem::getInstance()->addListener(ESCAPE_EVENT, this);
	EventSystem::getInstance()->addListener(LEFT_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(RIGHT_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(UP_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(DOWN_ARROW_EVENT, this);
	EventSystem::getInstance()->addListener(SPACE_BAR_EVENT, this);
}

void InputTranslator::cleanupInputTranslator()
{
	EventSystem::getInstance()->removeListener(ADD_UNIT_EVENT, this);
	EventSystem::getInstance()->removeListener(DELETE_UNIT_EVENT, this);
	EventSystem::getInstance()->removeListener(PAUSE_EVENT, this);
	EventSystem::getInstance()->removeListener(ESCAPE_EVENT, this);
	EventSystem::getInstance()->removeListener(LEFT_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(RIGHT_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(UP_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(DOWN_ARROW_EVENT, this);
	EventSystem::getInstance()->removeListener(SPACE_BAR_EVENT, this);
}

void InputTranslator::handleEvent(const Event & theEvent)
{
	if (theEvent.getType() == ADD_UNIT_EVENT)
	{
		const AddUnitEvent& addEvent = static_cast<const AddUnitEvent&>(theEvent);
		//cout << addEvent.getPosX();
		//cout << addEvent.getPosY();
		EventSystem::getInstance()->fireEvent(InstantiateEvent(addEvent.getPosX(), addEvent.getPosY()));
		//mManager->addUnits(addEvent.getPosX(), addEvent.getPosY(), mASSET_PATH + mSMURF_FILE, mASSET_PATH + mDEAN_FILE);
		//addUnits(addEvent.getPosX(), addEvent.getPosY(), addEvent.getFilePath1(), addEvent.getFilePath2());

	}
	if (theEvent.getType() == DELETE_UNIT_EVENT)
	{
		const DeleteUnitEvent& deleteEvent = static_cast<const DeleteUnitEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(RemoveEvent());
		//mManager->checkWhichUnitIsClicked(deleteEvent.getPosX(), deleteEvent.getPosY());

	}
	if (theEvent.getType() == PAUSE_EVENT)
	{
		const PauseEvent& pauseEvent = static_cast<const PauseEvent&>(theEvent);
 		EventSystem::getInstance()->fireEvent(TempStopEvent());
		//mManager->setAnimation(pauseEvent.getAnim());
		//checkWhichUnitIsClicked(deleteEvent.getPosX(), deleteEvent.getPosY());

	}
	if (theEvent.getType() == ESCAPE_EVENT)
	{
		const EscapeEvent& escapeEvent = static_cast<const EscapeEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(StopEvent());
		//Game::getInstance()->setDone(escapeEvent.getBool());
		//setAnimation(pauseEvent.getAnim());
		//checkWhichUnitIsClicked(deleteEvent.getPosX(), deleteEvent.getPosY());

	}
	if (theEvent.getType() == UP_ARROW_EVENT)
	{
		const UpArrowEvent& upEvent = static_cast<const UpArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveUpEvent());
	}
	if (theEvent.getType() == RIGHT_ARROW_EVENT)
	{
		const RightArrowEvent& upEvent = static_cast<const RightArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveRightEvent());
	}
	if (theEvent.getType() == LEFT_ARROW_EVENT)
	{
		const LeftArrowEvent& upEvent = static_cast<const LeftArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveLeftEvent());
	}
	if (theEvent.getType() == DOWN_ARROW_EVENT)
	{
		const DownArrowEvent& upEvent = static_cast<const DownArrowEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(MoveDownEvent());
	}
	if (theEvent.getType() == SPACE_BAR_EVENT)
	{
		const SpaceBarEvent& spaceEvent = static_cast<const SpaceBarEvent&>(theEvent);
		EventSystem::getInstance()->fireEvent(NextLevelEvent());
	}
		
}

void InputTranslator::updateInputTranslator(double dt)
{
}
