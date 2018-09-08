#pragma once
#include "Trackable.h"
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
struct Collider : public Trackable
{
public:
	Collider();
	~Collider();

	void setRadius(double myRadius);
	void setPosX( int myPos);
	void setPosY(int myPos);
	bool isColliding(Collider colliderLeft);

	double getRadius();
	int getPosX();
	int getPosY();
private:
	double mRadius;
	int mPosX;
	int mPosY;

};