#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::increaseLevel()
{
	mCurrentLevel++;
}

bool Level::doneLevel()
{
	return true;
}

void Level::setLevel(int mylevel)
{
	mCurrentLevel = mylevel;
}

int Level::getCurrentLevel()
{
	return mCurrentLevel;
}
