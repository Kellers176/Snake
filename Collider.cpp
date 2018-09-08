#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::setRadius(double myRadius)
{
	mRadius = myRadius;
}

void Collider::setPosX(int myPos)
{
	mPosX = myPos;
}

void Collider::setPosY(int myPos)
{
	mPosY = myPos;
}

bool Collider::isColliding(Collider colliderLeft)
{
	double distance = sqrt((mPosX - colliderLeft.getPosX()) * (mPosX - colliderLeft.getPosX())
		+ ((mPosY - colliderLeft.getPosY()) * (mPosY - colliderLeft.getPosY())));

	if (distance < colliderLeft.getRadius() + mRadius)
	{
		return true;
	}
	return false;
}

double Collider::getRadius()
{
	return mRadius;
}

int Collider::getPosX()
{
	return mPosX;
}

int Collider::getPosY()
{
	return mPosY;
}
