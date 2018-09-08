#include "FoodManager.h"
#include <random>
#include "Game.h"

using namespace std;

FoodManager::FoodManager()
{
	mFoodHeight = 40;
	mFoodHeight = 40;
	mFoodX = 0;
	mFoodY = 0;
}

FoodManager::FoodManager(GraphicsBuffer buffer, int myX, int myY, int Length, int rows, int cols, int ScreenWidth, int screenHeight)
{
	mDisplayWidth = ScreenWidth;
	mDisplayHeight = screenHeight;
	mFoodX = myX;
	mFoodPrevX = mFoodX;

	mFoodY = myY;
	mFoodPrevY = mFoodY;


	mAnimation = new Animation(rows*cols, true);
	mAnimation->splitSheet(buffer, Length, rows, cols);
	mLength = Length;
}

FoodManager::~FoodManager()
{
	delete mFood;
	delete mAnimation;
}

void FoodManager::updateFood(int deltaTie)
{
	mAnimation->update(deltaTie);
}

int FoodManager::getFoodLocX()
{
	return mFoodX;
}

int FoodManager::getFoodLocY()
{
	return mFoodY;
}

int FoodManager::getFoodWidth()
{
	return mFoodWidth;
}

int FoodManager::getFoodHeight()
{
	return mFoodHeight;
}

Food * FoodManager::getCurrentFood()
{
	return mFood;
}





void FoodManager::moveLocation(GridManager * myGrid, int row, int col)
{
	//srand(time(NULL));
	int myPos;
	Grid *tmp = myGrid->getGrid();
	do
	{
		myPos = (rand() % (row * col));
		mFoodX = tmp[myPos].getPoxX();
		mFoodY = tmp[myPos].getPosY();
	} while ((tmp[myPos].getPoxX() > mDisplayWidth - 80) || (tmp[myPos].getPosY() > mDisplayHeight - 80) || (tmp[myPos].getPoxX() < 0 + 80) || (tmp[myPos].getPosY() < 0 + 80));
	mFoodPrevX = mFoodX;
	mFoodPrevY = mFoodY;
	tmp = NULL;
}


void FoodManager::drawMyFood()
{
	mAnimation->drawSprites(mFoodX, mFoodY, 40);
	//mFood->drawMyFood(mFoodX, mFoodY);
}

void FoodManager::setFoodSprite(Sprite myFood)
{
	mFoodSprite = myFood;
}

