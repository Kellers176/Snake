/*Author: Kelly Herstine
Class: EGP-310
<Section 01>
Assignment: Assignment 2
Certification of Authenticity:
I certify that this assignment is entirely my own work.*/
#include "GraphicsBufferManager.h"

GraphicsBufferManager::GraphicsBufferManager()
{
	mGraphicsCurrentIndex = 0;
	/*GraphicsBuffer woodsBuffer(mASSET_PATH, mOTHER_BACKGROUND_FILENAME);
	GraphicsBuffer smurfBuffer(mASSET_PATH, mSMURF_FILE);
	GraphicsBuffer deanBuffer(mASSET_PATH, mDEAN_FILE);
	GraphicsBuffer myBlackBuffer;
	addGraphicsBuffer(woodsBuffer);
	addGraphicsBuffer(smurfBuffer);
	addGraphicsBuffer(deanBuffer);*/
}

GraphicsBufferManager::~GraphicsBufferManager()
{
	clearGraphicsBufferManager();
}

//void GraphicsBufferManager::addGraphicsBuffer(GraphicsBuffer myBuffer)
//{
//	mMap.emplace(mGraphicsCurrentIndex, myBuffer);
//	mGraphicsCurrentIndex++;
//}

void GraphicsBufferManager::addGraphicsBuffer(string myPath)
{
	mMap[mGraphicsCurrentIndex] = new GraphicsBuffer(myPath);
	mGraphicsCurrentIndex++;
}

void GraphicsBufferManager::deleteGraphicsBuffer(int currentKey)
{
		delete mMap[currentKey];
		mMap.erase(currentKey);
}

GraphicsBuffer* GraphicsBufferManager::getGraphicsBuffer(int index)
{
	return mMap.at(index);
}



void GraphicsBufferManager::clearGraphicsBufferManager()
{
	for (std::map<int, GraphicsBuffer*>::iterator itr = mMap.begin(); itr != mMap.end(); itr++)
	{
		delete(itr->second);
	}
	mMap.clear();

}
