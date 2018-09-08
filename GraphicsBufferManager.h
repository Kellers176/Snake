#pragma once
/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "Trackable.h"
#include <map>
#include "GraphicsBuffer.h"

using namespace std;

class GraphicsBufferManager : public Trackable
{
public:
	GraphicsBufferManager();
	~GraphicsBufferManager();

	/*void addGraphicsBuffer(GraphicsBuffer myBuffer);*/
	void addGraphicsBuffer(string myPath);
	void deleteGraphicsBuffer(int currentKey); //may need to change this
	GraphicsBuffer* getGraphicsBuffer(int index);

	

	void clearGraphicsBufferManager();//remove and delete all graphicsBuffers (not the backbuffer)



private:
	map<int, GraphicsBuffer*> mMap;
	int mGraphicsCurrentIndex;
	const string mASSET_PATH = "..\\..\\shared\\assets\\";
	const string mOTHER_BACKGROUND_FILENAME = "Woods.png";
	const string mSMURF_FILE = "smurf_sprites.png";
	const string mDEAN_FILE = "dean_sprites.png";
	const string FONT_FILENAME = "cour.ttf";
	GraphicsBuffer woodsBuffer;
	GraphicsBuffer smurfBuffer;
	GraphicsBuffer deanBuffer;


};