#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include "Sprite.h"
#include "Timer.h"
#include "System.h"
#include "Timer.h"
#include <vector>
#include <iostream>
using namespace std;

class Animation : public Trackable
{
	friend class Game;
public:
	Animation();
	Animation(int myInt, bool myBool);
	~Animation();

	void addSprite(Sprite* thisSprite);
	void addSecondSprite(Sprite newSprite);
	void addSpritesByFileName(string assetPath, int sizeX, int sizeY);
	void update(double deltaTime); //check current sprite
	Sprite* getCurrentSprite();
	void speedUpAnimation();
	void slowDownAnimation();
	int getCurrentIndex();
	void drawSprites(int x, int y, int length);

	void splitSheet(GraphicsBuffer myBuffer, int size, int row, int col);

	void setFrames(int myFrames);



private:
	vector<Sprite*> mSprites;
	GraphicsBuffer* mBuffer;
	Sprite* mArray;
	int mArrayLength;
	bool mLoop;
	int mSpriteAmount;
	Timer mAnimationTimer;
	Sprite mCurrentSprite;
	int mCurrentIndex;
	double mCurrentFrameTime;
	Timer mTimer;
	int FPS = 40;
};