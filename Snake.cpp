#include "Snake.h"
#include "Game.h"
#include <iostream>
using namespace std;

Snake::Snake()
{
	mPosX = 400;
	mPosY = 280;
	mSpeed = mLevelManager.getSpeed();
	oldDirection = Direction::left;
}

Snake::~Snake()
{
	for (int i = 0; i < mSnakeBody.size(); i++)
	{
		delete(mSnakeBody.at(i));
	}
	mSnakeBody.clear();
}

void Snake::drawMySnake(Sprite& mySprite, int mylocationX, int mylocationY)
{
	mSnakeManager.drawActualSprite(mySprite, mylocationX, mylocationY);
}

void Snake::draw()
{
	for (int i = 0; i < mSnakeBody.size(); i++)
	{
		mSnakeBody.at(i)->drawSnakePart();
	}
}

void Snake::changePosX(int pos)
{
	mPosX += pos;
}

void Snake::changePosY(int pos)
{
	mPosY += pos;
}

void Snake::addSnakeParts(Sprite & mySprite, int myLocationX, int myLocationY)
{
	SnakeBody *tmp = new SnakeBody;
	tmp->setPosition(myLocationX, myLocationY);
	tmp->setSprite(mySprite);
	mSnakeBody.push_back(tmp);
	mSnakeLength++;
	
}

int Snake::getLastLocationX()
{
	return mSnakeBody.at(mSnakeBody.size() - 1)->mSnakeBodyPosX;
}

int Snake::getLastLocationY()
{
	return mSnakeBody.at(mSnakeBody.size() - 1)->mSnakeBodyPosY;
}

int Snake::getSize()
{
	return mSnakeBody.size();
}

void Snake::resetSnake()
{
	for (int i = 0; i < mSnakeBody.size(); i++)
	{
		delete mSnakeBody.at(i);
	}
	mSnakeBody.clear();

	oldDirection = Direction::left;
}

void Snake::setPosX(int x)
{
	mPosX = x;

}

void Snake::setPosY(int y)
{
	mPosY = y;
}

bool Snake::isColliding(WallManager * myManager)
{

	for (int i = 1; i < mSnakeBody.size(); i++)
	{
		if (mSnakeBody.at(0)->mSnakeBodyPosX == mSnakeBody.at(i)->mSnakeBodyPosX && mSnakeBody.at(0)->mSnakeBodyPosY == mSnakeBody.at(i)->mSnakeBodyPosY)
		{
			bool isSomething = mLevelManager.finishLevel();
			return isSomething;
		}
	}

	Wall *tmp = myManager->getWall();

	for (int i = 0; i < myManager->getWallLength(); i++)
	{
		if (mSnakeBody.at(0)->mSnakeBodyPosX == tmp[i].getPosX() && mSnakeBody.at(0)->mSnakeBodyPosY == tmp[i].getPosY())
		{
			bool isSomething = mLevelManager.finishLevel();
			return isSomething;
			
		}
	}


	return false;
}

bool Snake::isCollidingFood(FoodManager * myFoodManager, GridManager * myGridManager, int rows, int columns)
{
	if (mSnakeBody.at(0)->mSnakeBodyPosX == myFoodManager->getFoodLocX() && mSnakeBody.at(0)->mSnakeBodyPosY == myFoodManager->getFoodLocY())
	{
		return true;
	}
	return false;
}

bool Snake::isCollidingPowerUp(PowerUp *myUp)
{
	if (mSnakeBody.at(0)->mSnakeBodyPosX == myUp->getPosX() && mSnakeBody.at(0)->mSnakeBodyPosY == myUp->getPosY())
	{
		switch (myUp->getType())
		{
		case SPEED_SNAKE_UP:
			myUp->setTypeOfPowerUp(END);
			Game::getInstance()->getLevelManager().setSpeed(170.0);
			break;
		case SLOW_SNAKE_DOWN:
			myUp->setTypeOfPowerUp(END);
			Game::getInstance()->getLevelManager().setSpeed(400.0);
			break;
		case POINT_BOOST:
			myUp->setTypeOfPowerUp(END);
			Game::getInstance()->getLevelManager().addPoints();
			Game::getInstance()->getLevelManager().addPoints();
			Game::getInstance()->getLevelManager().addPoints();
			Game::getInstance()->getLevelManager().addPoints();
			break;
		default:
			break;
		}
		return true;
	}
	return false;
}



void Snake::movePosition()
{
	mSpeed = Game::getInstance()->getLevelManager().getSpeed();
	if (mTimer.getElapsedTime() > mSpeed)
	{
		if (isUnitDown)
		{
			mPosY += 40;
			oldDirection = Direction::down;
		}
		else if (isUnitLeft)
		{
			mPosX -= 40;
			oldDirection = Direction::left;
		}
		else if (isUnitRight)
		{
			mPosX += 40;
			oldDirection = Direction::right;
		}
		else if (isUnitUp)
		{
			mPosY -= 40;
			oldDirection = Direction::up;
		}
		else
		{
			//move in old direction
			if (oldDirection == Direction::down)
			{
				mPosY += 40;
			}
			else if (oldDirection == Direction::left)
			{
				mPosX -= 40;
			}
			else if (oldDirection == Direction::right)
			{
				mPosX += 40;
			}
			else if (oldDirection == Direction::up)
			{
				mPosY -= 40;
			}
		}
		for (int i = mSnakeBody.size() - 1; i > 0; i--)
		{
			mSnakeBody.at(i)->mSnakeBodyPosX = mSnakeBody.at(i - 1)->mSnakeBodyPosX;
			mSnakeBody.at(i)->mSnakeBodyPosY = mSnakeBody.at(i - 1)->mSnakeBodyPosY;
		}
		mSnakeBody.at(0)->mSnakeBodyPosX = mPosX;
		mSnakeBody.at(0)->mSnakeBodyPosY = mPosY;
		mTimer.start();
	}
}


int Snake::getPosX()
{
	return mPosX;
}

int Snake::getPosY()
{
	return mPosY;
}

SnakeBody::SnakeBody()
{
	mSnakeBodyPosX = 0;
	mSnakeBodyPosY = 0;

}

SnakeBody::~SnakeBody()
{
}

void SnakeBody::drawSnakePart()
{
	mSnakeBodySprite.getGraphicsBuffer()->drawBitmap(mSnakeBodyPosX, mSnakeBodyPosY);
}

void SnakeBody::setSprite(Sprite & thisSprites)
{
	mSnakeBodySprite = thisSprites;
	mCollider.setPosX(mSnakeBodyPosX);
	mCollider.setPosY(mSnakeBodyPosY);
	mCollider.setRadius(mSnakeBodySprite.getWidthOfSprite() / 2.0);
}

void SnakeBody::setPosition(int positionX, int positionY)
{
	mSnakeBodyPosX = positionX;
	mSnakeBodyPosY = positionY;
}

Collider SnakeBody::getCollider()
{
	return mCollider;
}

void SnakeBody::resetPositions()
{
	mSnakeBodyPosX = 0;
	mSnakeBodyPosY = 0;

}

