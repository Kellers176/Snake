#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Sprite.h"
#include"Trackable.h"
#include "GridManager.h"
#include "Food.h"

class FoodManager : public Trackable
{
public:
	FoodManager();
	FoodManager(GraphicsBuffer buffer, int myLocY, int myLocX, int Length, int rows, int cols, int ScreenWidth, int screenHeight);
	~FoodManager();

	void updateFood(int deltaTime);
	int getFoodLocX();
	int getFoodLocY();
	int getFoodWidth();
	int getFoodHeight();
	Food *getCurrentFood();

	void moveLocation(GridManager *myGrid, int row, int col);
	void drawMyFood();

	void setFoodSprite(Sprite myFood);

private:
	Animation* mAnimation;
	Sprite mFoodSprite;
	Food *mFood;
	int mLength;
	int mDisplayWidth;
	int mDisplayHeight;
	int mFoodX;
	double deltaTime;
	int mFoodY;
	int mFoodPrevX;
	int mFoodPrevY;
	int mFoodWidth;
	int mFoodHeight;
};