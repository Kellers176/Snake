#pragma once
#include "Trackable.h"
#include "Animation.h"
class Unit : public Trackable
{
public:
	Unit();
	~Unit();

	void updateUnit();
	void drawCurrentAnimationSprite(Animation myAnimation); //may need to change this to sprite
	void setAnimation(Animation newAnimation); //switch to a new animation



private:
	int mLocX;
	int mLocY;
	Animation mAnimations;
};
