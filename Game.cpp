#include "Game.h"
#include "AddUnitEvent.h"
#include "DeleteUnitEvent.h"
#include "PauseEvent.h"
#include "EscapeEvent.h"
#include "PowerUp.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/

Game* Game::mpsInstance = NULL;

Game::Game()
{
	mPosX = 0;
	mPosY = 0;
	mSpaceCount = 0;
	mPosXOfBuffer = 0.67;
	mPosYOfBuffer = 0.6;
	mDone = false;
	mMousePositionX = 350;
	mMousePositionY = 300;
	isShowing = true;
	StartGame = false;
	mWidth = 800;
	mHeight = 600;
	setApart = 40;
	mFPS = 0;
	mRows = 15;
	mCols = 20;
	mShouldPress = false;
	isFood = false;
	mPowerUpRate = mLevelManager.getPowerUpFrequency();
	mPowerUpStart = false;
	initGame();
	
}

Game::~Game()
{
	delete mGridManager;
	delete mFoodManager;
	delete mWallManager;
	delete mPowerUp;
	for (int i = 0; i < mPowerVector.size() - 1; i++)
	{
		delete mPowerVector[i];
	}
	mPowerVector.clear();
}

void Game::initGame()
{
	mSystem.mGraphicsSystem.initGraphicsSystem();
	mSystem.initSystem();
	mLevelManager.init();
	EventSystem::initInstance();
	mTranslator.initInputTranslator();
	mManager.addGraphicsBuffer(mGRID_SPRITE);
	mManager.addGraphicsBuffer(mSNAKE_SPRITE);
	mManager.addGraphicsBuffer(mSNAKE_BODY_SPRITE);
	mManager.addGraphicsBuffer(mFOOD_SPRITE);
	mManager.addGraphicsBuffer(mWALL_SPRITE);
	mManager.addGraphicsBuffer(mPOWER_UP_SPRITE);
	mManager.addGraphicsBuffer(mPOWER_DOWN_SPRITE);
	mManager.addGraphicsBuffer(mBONUS_POINTS_SPRITE);
	mManager.addGraphicsBuffer(mSNAKE_BACKGROUND);
	mGridManager = new GridManager(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(0)), mRows, mCols, 40);
	mFoodManager = new FoodManager(*mManager.getGraphicsBuffer(3), 400, 320, 40, 1, 2, mWidth, mHeight);
	mWallManager = new WallManager(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(4)), mCols, mRows, 40);


	
	mPowerUp = new PowerUp(SPEED_SNAKE_UP, *mManager.getGraphicsBuffer(0), 100, 100, 40, 1, 1);
	mPowerVector.push_back(mPowerUp);

	mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(1)), mSnake.getPosX(), mSnake.getPosY());

	for (int i = 0; i < mLevelManager.getStartLengthSegments(); i++)
	{
		mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getPosX() + setApart, mSnake.getPosY());
		setApart += 40;
	}

	EventSystem::getInstance()->addListener(EXIT_EVENT, this);
	EventSystem::getInstance()->addListener(MOVE_UP_EVENT, this);
	EventSystem::getInstance()->addListener(MOVE_DOWN_EVENT, this);
	EventSystem::getInstance()->addListener(MOVE_LEFT_EVENT, this);
	EventSystem::getInstance()->addListener(MOVE_RIGHT_EVENT, this);

	drawSystem(mSystem, mHeight, mWidth);
	mFoodManager->moveLocation(mGridManager, mCols, mRows);
}

void Game::cleanupGame()
{
	mSystem.mGraphicsSystem.cleanGraphicsSystem();
	EventSystem::cleanupInstance();
	mManager.clearGraphicsBufferManager();
	mUnitManager.clearUnits();
	
}

void Game::drawSystem(System&  mySystem, int myHeight, int myWidth)
{
	mySystem.mGraphicsSystem.display(myHeight, myWidth);
}

Game * Game::getInstance()
{
	return mpsInstance;
}

void Game::initInstance()
{
	if (mpsInstance == NULL)
	{
		mpsInstance = new Game;
	}
}

void Game::cleanupInstance()
{
	delete mpsInstance;
	mpsInstance = NULL;
}

void Game::doLoop()
{
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker; //this stays
	const string INIT_TRACKER_NAME = "init"; //this stays

	mDt = 16.7;
	int count = 0;

	while (!mDone)
	{
		srand(time(NULL));
		mTimer.start();
		pPerformanceTracker->startTracking(INIT_TRACKER_NAME);//leave this alone

		mDone = getInput(count);
		update(mDt);
		Render(mMousePositionX, mMousePositionY);

		mTimer.sleepUntilElapsed(mDt);
		mFPS = 1000.0 / pPerformanceTracker->getElapsedTime(INIT_TRACKER_NAME);
		cout << pPerformanceTracker->getElapsedTime(INIT_TRACKER_NAME) << endl;
		pPerformanceTracker->clearTracker(INIT_TRACKER_NAME);
	}
	cleanupGame();
	mUnitManager.clearUnits();
	delete(pPerformanceTracker); //this stays
	system("pause");
}

bool Game::getInput(int& myCount)
{
	myCount++;

	if (mEscapeIsPressed && myCount > 20)
	{
		mDone = true;
		return getDone();
		myCount = 0;
	}
	if (mRightKeyIsPressed)
	{
		mSnake.isUnitDown = false;
		mSnake.isUnitLeft = false;
		mSnake.isUnitRight = true;
		mSnake.isUnitUp = false;

		mRightKeyIsPressed = false;
	}
	if (mLeftKeyIsPressed)
	{
		mSnake.isUnitDown = false;
		mSnake.isUnitLeft = true;
		mSnake.isUnitRight = false;
		mSnake.isUnitUp = false;

		mLeftKeyIsPressed = false;
	}
	if (mUpKeyIsPressed)
	{
		mSnake.isUnitDown = false;
		mSnake.isUnitLeft = false;
		mSnake.isUnitRight = false;
		mSnake.isUnitUp = true;

		mUpKeyIsPressed = false;
	}
	if (mDownKeyIsPressed)
	{
		mSnake.isUnitDown = true;
		mSnake.isUnitLeft = false;
		mSnake.isUnitRight = false;
		mSnake.isUnitUp = false;

		mDownKeyIsPressed = false;
	}
	if (mSpaceIsPressed)
	{
		Level1 = false;
		StartGame = true;
		mSpaceIsPressed = false;
	}	
	return getDone();
}

void Game::update(double deltaTime)
{
	mUnitManager.update(deltaTime);
	mSystem.getInputSystem().updateInputSystem(deltaTime);
	mLevelManager.update();
	mFoodManager->updateFood(deltaTime);

	if (rand() % mPowerUpRate == 1 && !mPowerUpStart)
	{
		mPowerUpStart = true;

		int output = rand() % 3;
		int position;

		Grid *tmp = mGridManager->getGrid();

		do
		{
			position = rand() % (mCols * mRows);
		} while ((tmp[position].getPoxX() > mWidth - 160) || (tmp[position].getPosY() > mHeight - 160) || (tmp[position].getPoxX() < 0 + 160) || (tmp[position].getPosY() < 0 + 160 
			|| tmp[position].getPoxX() == mFoodManager->getFoodLocX() || tmp[position].getPosY() == mFoodManager->getFoodLocY()));

		switch (output)
		{
		case 0:
			mPowerUp = new PowerUp(SPEED_SNAKE_UP, *mManager.getGraphicsBuffer(5), tmp[position].getPoxX(), tmp[position].getPosY(), 40, 1, 2);
			mPowerVector.push_back(mPowerUp);
			break;
		case 1:
			mPowerUp = new PowerUp(SLOW_SNAKE_DOWN, *mManager.getGraphicsBuffer(6), tmp[position].getPoxX(), tmp[position].getPosY(), 40, 1, 2);
			mPowerVector.push_back(mPowerUp);
			break;
		case 2:
			mPowerUp = new PowerUp(POINT_BOOST, *mManager.getGraphicsBuffer(7), tmp[position].getPoxX(), tmp[position].getPosY(), 40, 1, 2);
			mPowerVector.push_back(mPowerUp);
			break;
		default:
			break;
		}
	}
	mPowerUp->update(deltaTime);
}

void Game::showFrameRate()
{
	Font myFont(20, mASSET_PATH + FONT_FILENAME);
	white.setColor(0, 255, 0);
	mSystem.mGraphicsSystem.writeText(150, 560, myFont, white, "Frame Rate: " + to_string(mFPS));
}

void Game::Render(int mXPosition, int mYPosition)
{
	mSystem.mGraphicsSystem.drawColorBuffer(0, 0, 0);
	Level();
	mSystem.mGraphicsSystem.flipDisplay();
}

void Game::Level()
{
	//start screen
	if (mLevelManager.getCurrentLevel() == 0)
	{
		Sprite TMP(600, 800, 0, 0, mManager.getGraphicsBuffer(8));
		TMP.getGraphicsBuffer()->drawBitmap(0, 0);
		Font myFont(40, mASSET_PATH + FONT_FILENAME);
		white.setColor(0, 0, 0);
		mSystem.mGraphicsSystem.writeText(370, 100, myFont, white, "Welcome to Snake!");
		mSystem.mGraphicsSystem.writeText(370, 200, myFont, white, "Press Space to Continue");
		showFrameRate();
		mSystem.mGraphicsSystem.flipDisplay();
	}
	//level 1
	if (mLevelManager.getCurrentLevel() == 1)
	{

		bool gotPowerUp = false;
		mGridManager->drawMyGrid();
		mWallManager->drawMyWallManager();
		bool isDone = mSnake.isColliding(mWallManager);

		if (mSnake.getPosY() > 520)
		{
			isDone = true;
		}
		isFood = mSnake.isCollidingFood(mFoodManager, mGridManager, mRows, mCols);
		if (isFood)
		{
			mFoodManager->moveLocation(mGridManager, mRows, mCols);
			mLevelManager.addPoints();
			mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getLastLocationX(), mSnake.getLastLocationY());
		}
		if (isDone)
		{
			mLevelManager.getLevel().setLevel(6);
		}

		mSnake.draw();
		mFoodManager->drawMyFood();
		if (mPowerUpStart)
		{
			mPowerUp->drawMyPowerUp();
		}

		gotPowerUp = mSnake.isCollidingPowerUp(mPowerUp);
		if (gotPowerUp)
		{
			mPowerUpStart = false;
			gotPowerUp = false;
		}
		showFrameRate();
		mLevelManager.showMyPoints();
		mLevelManager.showMyLevel();
		mSnake.movePosition();

	}
	//transition check
	if (mSnake.getSize() == mLevelManager.getEndLength() && mLevelManager.getCurrentLevel() == 1)
	{
		mLevelManager.setLevel(2);
		resetSnake();
		mLevelManager.setSpeed(250.0);

		mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(1)), mSnake.getPosX(), mSnake.getPosY());
		for (int i = 0; i < mLevelManager.getStartLengthSegments(); i++)
		{
			mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getPosX() + 40, mSnake.getPosY());
			setApart += 40;
		}
		mLevelManager.setEndLength(16);


	}
	//level 2
	if (mLevelManager.getCurrentLevel() == 2)
	{
		bool gotPowerUp = false;
		mGridManager->drawMyGrid();
		mWallManager->drawMyWallManager();
		mLevelManager.setPowerUpFrequency(15);
		mSnake.draw();
		mSnake.movePosition();
		bool isDone = false;
		isDone = mSnake.isColliding(mWallManager);
		checks(isDone);
		
		isFood = mSnake.isCollidingFood(mFoodManager, mGridManager, mRows, mCols);
		if (isFood)
		{
			mFoodManager->moveLocation(mGridManager, mRows, mCols);
			mLevelManager.addPoints();
			mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getLastLocationX(), mSnake.getLastLocationY());
		}
		if (isDone)
		{
			mLevelManager.getLevel().setLevel(6);
		}
		mFoodManager->drawMyFood();
		if (mPowerUpStart)
		{
			mPowerUp->drawMyPowerUp();
		}

		gotPowerUp = mSnake.isCollidingPowerUp(mPowerUp);
		if (gotPowerUp)
		{
			mPowerUpStart = false;
		}
		showFrameRate();
		mLevelManager.showMyPoints();
		mLevelManager.showMyLevel();
	}
	//Transition
	if (mSnake.getSize() == mLevelManager.getEndLength() && mLevelManager.getCurrentLevel() == 2)
	{
		mLevelManager.setLevel(3);
		resetSnake();
		mLevelManager.setSpeed(200.0);

		mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(1)), mSnake.getPosX(), mSnake.getPosY());
		for (int i = 0; i < mLevelManager.getStartLengthSegments(); i++)
		{
			mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getPosX() + 40, mSnake.getPosY());
			setApart += 40;
		}
		mLevelManager.setEndLength(16);
	}
	//level 3
	if (mLevelManager.getCurrentLevel() == 3)
	{
		mLevelManager.setPowerUpFrequency(10);
		bool gotPowerUp = false;
		mGridManager->drawMyGrid();
		mWallManager->drawMyWallManager();
		mSnake.draw();
		mSnake.movePosition();
		bool isDone = false;
		isDone = mSnake.isColliding(mWallManager);
		checks(isDone);

		isFood = mSnake.isCollidingFood(mFoodManager, mGridManager, mRows, mCols);
		if (isFood)
		{
			mFoodManager->moveLocation(mGridManager, mRows, mCols);
			mLevelManager.addPoints();
			mSnake.addSnakeParts(Sprite(40, 40, 0, 0, mManager.getGraphicsBuffer(2)), mSnake.getLastLocationX(), mSnake.getLastLocationY());
		}
		if (isDone)
		{
			mLevelManager.getLevel().setLevel(6);
		}
		mFoodManager->drawMyFood();
		if (mPowerUpStart)
		{
			mPowerUp->drawMyPowerUp();
		}

		gotPowerUp = mSnake.isCollidingPowerUp(mPowerUp);
		if (gotPowerUp)
		{
			mPowerUpStart = false;
		}
		showFrameRate();
		mLevelManager.showMyPoints();
		mLevelManager.showMyLevel();
	}
	//transition
	if (mSnake.getSize() == mLevelManager.getEndLength() && mLevelManager.getCurrentLevel() == 3)
	{
		mLevelManager.setLevel(4);
	}
	//win screen
	if (mLevelManager.getCurrentLevel() == 4)
	{
		Sprite TMP(600, 800, 0, 0, mManager.getGraphicsBuffer(8));
		TMP.getGraphicsBuffer()->drawBitmap(0, 0);
		Font myFont(40, mASSET_PATH + FONT_FILENAME);
		white.setColor(0, 0, 0);
		mLevelManager.showMyPoints();
		mSystem.mGraphicsSystem.writeText(370, 100, myFont, white, "YOU WIN!");
		mSystem.mGraphicsSystem.writeText(370, 200, myFont, white, "Press Space to Exit");
		showFrameRate();
		mSystem.mGraphicsSystem.flipDisplay();
	}
	if (mLevelManager.getCurrentLevel() == 5)
	{
		mDone = true;
	}
	//Lose Screen
	if (mLevelManager.getCurrentLevel() == 6)
	{
		Sprite TMP(600, 800, 0, 0, mManager.getGraphicsBuffer(8));
		TMP.getGraphicsBuffer()->drawBitmap(0, 0);
		Font myFont(40, mASSET_PATH + FONT_FILENAME);
		white.setColor(0, 0, 0);
		mLevelManager.showMyPoints();
		mSystem.mGraphicsSystem.writeText(370, 100, myFont, white, "YOU LOSE!");
		mSystem.mGraphicsSystem.writeText(370, 200, myFont, white, "Press Space to Exit");
		showFrameRate();
		mSystem.mGraphicsSystem.flipDisplay();
	}
	if (mLevelManager.getCurrentLevel() == 7)
	{
		mDone = true;
	}
}

void Game::resetSnake()
{
	mSnake.isUnitDown = false;
	mSnake.isUnitLeft = false;
	mSnake.isUnitRight = false;
	mSnake.isUnitUp = false;
	mSnake.resetSnake();
	mSnake.setPosX(400);
	mSnake.setPosY(280);
}

void Game::checks(bool &mybool)
{
	if (mSnake.getPosY() > 520)
	{
		mybool = true;
	}
	if (mSnake.getPosX() > 720)
	{
		mybool = true;
	}
	if (mSnake.getPosY() < 40)
	{
		mybool = true;
	}
	if (mSnake.getPosX() < 40)
	{
		mybool = true;
	}
}

void Game::loadData()
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
	mGRID_SPRITE = data;

	getline(fin, data);
	mSNAKE_SPRITE = data;

	getline(fin, data);
	mWALL_SPRITE = data;


	getline(fin, data);
	mPOWER_UP_SPRITE = data;

	getline(fin, data);
	mPOWER_DOWN_SPRITE = data;

	getline(fin, data);
	mBONUS_POINTS_SPRITE = data;

	getline(fin, data);
	mSNAKE_BODY_SPRITE = data;
	
	getline(fin, data);
	mOTHER_BACKGROUND_FILENAME = data;

	getline(fin, data);
	mSMURF_FILE = data;

	getline(fin, data);
	mDEAN_FILE = data;
	
	getline(fin, data);
	mFOOD_SPRITE = data;

	getline(fin, data);
	FONT_FILENAME = data;


	fin.close();
	
}

void Game::setShouldPress(bool myBool)
{
	mShouldPress = myBool;
}

bool Game::getDone()
{
	return mDone;
}

void Game::setDone(bool myVar)
{
	mDone = myVar;
}

void Game::handleEvent(const Event & theEvent)
{
	if (theEvent.getType() == EXIT_EVENT)
	{
		mLeftIsPressed = false;
		mRightIsPressed = false;
		mEscapeIsPressed = true;
		mSpaceIsPressed = false;
		mSpaceIsPressed = false;
	}
	if (theEvent.getType() == MOVE_RIGHT_EVENT)
	{
		mLeftKeyIsPressed = false;
		mRightKeyIsPressed = true;
		mUpKeyIsPressed = false;
		mDownKeyIsPressed = false;
		mSpaceIsPressed = false;
	}
	if (theEvent.getType() == MOVE_LEFT_EVENT)
	{
		mLeftKeyIsPressed = true;
		mRightKeyIsPressed = false;
		mUpKeyIsPressed = false;
		mDownKeyIsPressed = false;
		mSpaceIsPressed = false;
	}
	if (theEvent.getType() == MOVE_UP_EVENT)
	{
		mLeftKeyIsPressed = false;
		mRightKeyIsPressed = false;
		mUpKeyIsPressed = true;
		mDownKeyIsPressed = false;
		mSpaceIsPressed = false;
	}
	if (theEvent.getType() == MOVE_DOWN_EVENT)
	{
		mLeftKeyIsPressed = false;
		mRightKeyIsPressed = false;
		mUpKeyIsPressed = false;
		mDownKeyIsPressed = true;
		mSpaceIsPressed = false;
	}
	if (theEvent.getType() == NEXT_LEVEL_EVENT)
	{
		mLeftKeyIsPressed = false;
		mRightKeyIsPressed = false;
		mUpKeyIsPressed = false;
		mDownKeyIsPressed = false;
		mSpaceIsPressed = true;

	}
}

LevelManager  &Game::getLevelManager()
{
	return mLevelManager;
}

int Game::getWidth()
{
	return mWidth;
}

int Game::getHeight()
{
	return mHeight;
}

