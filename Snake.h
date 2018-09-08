#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "GraphicsSystem.h"
#include "Timer.h"	
#include "Collider.h"
#include "LevelManager.h"
#include "WallManager.h"
#include "FoodManager.h"
#include "GridManager.h"
#include "PowerUp.h"
#include <vector>

enum Direction
{
	stop = -1,
	up,
	down,
	left,
	right,
};
struct SnakeBody
{
public:
	SnakeBody();
	~SnakeBody();

	void drawSnakePart();

	void setSprite(Sprite& thisSprites);
	void setPosition(int positionX, int positionY);
	Collider getCollider();

	void resetPositions();

	Sprite mSnakeBodySprite;
	int mSnakeBodyPosX;
	int mSnakeBodyPosY;
	Collider mCollider;
};

class Snake : public Trackable
{
public:
	Snake();
	~Snake();

	void drawMySnake(Sprite& mySprite, int myWidth, int myHeight);
	void draw();

	void changePosX(int pos);
	void changePosY(int pos);
	void addSnakeParts(Sprite& mySprite, int myLocationX, int myLocationY);
	int getLastLocationX();
	int getLastLocationY();

	int getSize();
	void resetSnake();
	void setPosX(int x);
	void setPosY(int y);


	bool isColliding(WallManager *myManager);
	bool isCollidingFood(FoodManager *myFoodManager, GridManager *myGridManager, int rows, int columns);
	bool isCollidingPowerUp(PowerUp *myUp);

	void movePosition();

	int getPosX();
	int getPosY();

	bool isUnitDown, isUnitRight, isUnitLeft, isUnitUp;

private:
	double mSpeed;
	Direction oldDirection;
	FoodManager mFoodManager;
	LevelManager mLevelManager;
	int mStartLengthOfSnake;
	int mSnakeLength;
	int mPosX;
	int mPosY;
	int mPreviousPosX;
	int mPreviousPosY;
	Timer mTimer;
	vector<SnakeBody*> mSnakeBody;
	GraphicsSystem mSnakeManager;

};