#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "System.h"
#include "Color.h"
#include "GraphicsBuffer.h"
#include "EventListener.h"
#include "Event.h"
#include "Level.h"
#include <fstream>
#include <string>

using namespace std;


class LevelManager : public EventListener
{
public:
	LevelManager();
	LevelManager(int wallWidth, int wallHeight);
	~LevelManager();

	void init();
	void update();
	void setSpeed(int currentSpeed);
	void setPowerUpFrequency(double myFreq);
	void setEndLength(int endLength);
	void addPoints();
	void addPoints(int points);
	bool finishLevel();
	void setLevel(int myLevel);
	void loadLevelData();

	void restartScore();

	int getEndLength();

	int getStartLengthSegments();

	void showMyPoints();
	void showMyLevel();

	double getSpeed();
	double getPowerUpFrequency();

	void handleEvent(const Event & theEvent);

	int getCurrentLevel();
	Level & getLevel();


private:
	string mASSET_PATH = "..\\..\\shared\\assets\\";
	string FONT_FILENAME = "cour.ttf";
	string mFILE = "LevelInfo.txt";
	Color white;
	System mSystem;
	Level mLevel;

	bool mSpaceIsPressed;

	double mSpeedOfSnake;
	int mStartingNumberOfSegments;
	int mEndingNumberOfSegments;

	int mPoints;
	double mPowerUpFrequency;
	int mPointsPerFood;

	int mWallWidth;
	int mWallHeight;




};