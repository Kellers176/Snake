#include "LevelManager.h"
#include "EventSystem.h"
#include "NextLevelEvent.h"
#include "Game.h"


LevelManager::LevelManager()
{

	mSpeedOfSnake = 300.0;
	mStartingNumberOfSegments = 1;
	mEndingNumberOfSegments = 11;

	mPoints = 0;
	mPowerUpFrequency = 20.0;
	mPointsPerFood = 10;

	mWallWidth = 800;
	mWallHeight = 600;

}

LevelManager::LevelManager(int wallWidth, int wallHeight)
{
	mWallWidth = wallWidth;
	mWallHeight = wallHeight;
}

LevelManager::~LevelManager()
{

}

void LevelManager::init()
{
	EventSystem::getInstance()->addListener(NEXT_LEVEL_EVENT, this);
}

void LevelManager::update()
{
	if (mSpaceIsPressed == true) //& snake segments are maxed or something like this
	{
		mLevel.increaseLevel();
		mSpaceIsPressed = false;
	}
}


double LevelManager::getSpeed()
{
	return mSpeedOfSnake;
}

double LevelManager::getPowerUpFrequency()
{
	return mPowerUpFrequency;
}

void LevelManager::setSpeed(int currentSpeed)
{
	mSpeedOfSnake = currentSpeed;
}

void LevelManager::setPowerUpFrequency(double myFreq)
{
	mPowerUpFrequency = myFreq;
}

void LevelManager::setEndLength(int endLength)
{
	mEndingNumberOfSegments = endLength;
}

void LevelManager::addPoints()
{
	mPoints += mPointsPerFood;
}

void LevelManager::addPoints(int points)
{
	mPoints += points;
}

bool LevelManager::finishLevel()
{
	return mLevel.doneLevel();
}

void LevelManager::setLevel(int myLevel)
{
	mLevel.setLevel(myLevel);
}

void LevelManager::loadLevelData()
{
	string tmp;
	string data;
	ifstream fin;
	string key = "-";
	size_t pos = 0;

	fin.open(mFILE);

	getline(fin, data);
	mASSET_PATH = data;
	
	getline(fin, data);
	FONT_FILENAME = data;
	
	fin.close();
}

void LevelManager::restartScore()
{
	mPoints = 0;
}


int LevelManager::getEndLength()
{
	return mEndingNumberOfSegments;
}

int LevelManager::getStartLengthSegments()
{
	return mStartingNumberOfSegments;
}

void LevelManager::showMyPoints()
{
	//cout << mPoints << endl;
	Font myFont(40, mASSET_PATH + FONT_FILENAME);
	white.setColor(255, 255, 255);
	mSystem.mGraphicsSystem.writeText(100, 0, myFont, white, "Score: ");
	mSystem.mGraphicsSystem.writeText(200, 0, myFont, white, to_string(mPoints));
}

void LevelManager::showMyLevel()
{
	Font myFont(40, mASSET_PATH + FONT_FILENAME);
	white.setColor(255, 255, 255);
	mSystem.mGraphicsSystem.writeText(700, 0, myFont, white, "Level: ");
	mSystem.mGraphicsSystem.writeText(770, 0, myFont, white, to_string(mLevel.getCurrentLevel()));
}

void LevelManager::handleEvent(const Event & theEvent)
{
	if (theEvent.getType() == NEXT_LEVEL_EVENT)
	{
		mSpaceIsPressed = true;
		Game::getInstance()->setShouldPress(false);
	}
}

int LevelManager::getCurrentLevel()
{
	return mLevel.getCurrentLevel();
}

Level &LevelManager::getLevel()
{
	return mLevel;
}
