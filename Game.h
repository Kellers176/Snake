
#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include "Color.h"
#include "Font.h"
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include "Sprite.h"
#include "Trackable.h"
#include "System.h"
#include "Unit.h"
#include "Animation.h"
#include "Timer.h"
#include "GraphicsBufferManager.h"
#include "UnitManager.h"
#include "EventSystem.h"
#include "EventListener.h"
#include "InputSystem.h"
#include "InputTranslator.h"
#include "GridManager.h"
#include "Snake.h"
#include "FoodManager.h"
#include "LevelManager.h"
#include "WallManager.h"
#include "PowerUp.h"
#include <fstream>

#include <iostream>

#include <GraphicsLib.h>
#include <stdlib.h>

using namespace std;

//make static class
class Game :public EventListener
{
public:
	void initGame();
	void cleanupGame();
	void drawSystem(System& mySystem, int myWidth, int myHeight);

	static Game* getInstance();
	static void initInstance();
	static void cleanupInstance();

	void doLoop(); 
	bool getInput(int& myCount);
	void update(double deltaTime);
	void showFrameRate();
	void Render( int mXPosition, int mYPosition);
	void Level();
	void resetSnake();
	void checks(bool &mybool);
	void loadData();
	void setShouldPress(bool myBool);

	bool getDone();
	void setDone(bool myVar);
	void handleEvent(const Event &theEvent);
	LevelManager &getLevelManager();

	int getWidth();
	int getHeight();


private:
	Game();
	~Game();

	const string mFILE = "dataFile.txt";
	static Game *mpsInstance;
	 string mASSET_PATH = "..\\..\\shared\\assets\\";
	 string mGRID_SPRITE = "..\\midtermProjectSnake\\grid.png";
	 string mSNAKE_SPRITE = "..\\midtermProjectSnake\\snake.png";
	 string mWALL_SPRITE = "..\\midtermProjectSnake\\wall.png";
	 string mPOWER_UP_SPRITE = "..\\midtermProjectSnake\\powerUp.png";
	 string mPOWER_DOWN_SPRITE = "..\\midtermProjectSnake\\powerDown.png";
	 string mBONUS_POINTS_SPRITE = "..\\midtermProjectSnake\\bonusPoints.png";
	 string mSNAKE_BODY_SPRITE = "..\\midtermProjectSnake\\snakeBody.png";
	 string mSNAKE_BACKGROUND = "..\\midtermProjectSnake\\snakeBackground.png";
	 string mOTHER_BACKGROUND_FILENAME = "Woods.png";
	 string mSMURF_FILE = "smurf_sprites.png";
	 string mDEAN_FILE = "dean_sprites.png";
	 string mFOOD_SPRITE = "..\\midtermProjectSnake\\food.png";
	 string FONT_FILENAME = "cour.ttf";
	const int mF_CODE = 6;
	const int mENTER_CODE = 67;
	const int mESCAPE_CODE = 59;
	const int mS_CODE = 19;
	const int mSPACE_CODE = 75;

	InputTranslator mTranslator;
	
	vector<PowerUp*> mPowerVector;
	int mRows;
	int mCols;
	System mSystem;
	Snake mSnake;
	double mFPS;
	//need to change these to levels afterwards
	bool Level1;
	bool StartGame;
	bool mShouldPress;
	LevelManager mLevelManager;
	WallManager *mWallManager;
	GridManager* mGridManager;
	PowerUp *mPowerUp;
	bool isFood;
	Color white;
	UnitManager mUnitManager;
	GraphicsBufferManager mManager;
	Unit mUnit;
	Timer mTimer;
	FoodManager *mFoodManager;
	int mWidth;
	double mDt;
	int mHeight;
	int mRow;
	int mCol;
	int mSizeOfSmurfIndividual;
	int mPosX;
	int mPosY;
	int setApart;
	int mSpaceCount;
	float mPosXOfBuffer;
	float mPosYOfBuffer;
	bool mDone;
	int mX;
	int mY;
	int mPowerUpRate;
	bool mPowerUpStart;
	int mMousePositionX;
	int mMousePositionY;
	bool isShowing;
	bool mLeftIsPressed;
	bool mRightIsPressed;
	bool mEscapeIsPressed;

	bool mLeftKeyIsPressed;
	bool mRightKeyIsPressed;
	bool mUpKeyIsPressed;
	bool mDownKeyIsPressed;
	bool mSpaceIsPressed;
};


