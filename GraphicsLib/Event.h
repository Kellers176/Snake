#pragma once

#include <string>
#include <trackable.h>

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	PAUSE_EVENT,
	ADD_UNIT_EVENT,
	DELETE_UNIT_EVENT,
	ESCAPE_EVENT,
	CREATE_UNIT_EVENT,
	REMOVE_UNIT_EVENT,
	TEMP_STOP_EVENT,
	MOVE_UP_EVENT,
	MOVE_DOWN_EVENT,
	MOVE_LEFT_EVENT,
	MOVE_RIGHT_EVENT,
	UP_ARROW_EVENT,
	RIGHT_ARROW_EVENT,
	LEFT_ARROW_EVENT,
	DOWN_ARROW_EVENT,
	SPACE_BAR_EVENT,
	NEXT_LEVEL_EVENT,
	EXIT_EVENT,
	NUM_EVENT_TYPES
};

const string EVENT_NAMES[NUM_EVENT_TYPES] = { "Pause Event", "Add Unit Event", "Delete Unit Event", "Escape Event", "Create Unit Event", "Remove Unit Event",
		"Temp Stop Event", "Move Up Event", "Move Down Event", "Move Left Event", "Move Right Event", "Up Arrow Event", "Right Arrow Event", "Left Arrow Event",
		"Down Arrow Event", "Exit Event"
};

class Event :public Trackable
{
public:
	Event();
	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;


private:
	EventType mType;

};