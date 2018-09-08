/*Author: Kelly Herstine 
Class: EGP-310 
<Section 01> 
Assignment: Assignment 2
Certification of Authenticity: 
I certify that this assignment is entirely my own work.*/

#include <iostream>
#include <cassert>
#include <string>

#include "Game.h"

#include <iostream>

#include <GraphicsLib.h>
#include <stdlib.h>

using namespace std;

int main()
{
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker; //this stays
	const string INIT_TRACKER_NAME = "init"; //this stays
	EventSystem::initInstance();

		Game::initInstance();
 		Game* ptr = Game::getInstance();
		ptr->doLoop();
		Game::cleanupInstance();
		EventSystem::cleanupInstance();

	delete(pPerformanceTracker); //this stays
	gMemoryTracker.reportAllocations(cout); //this stays
	system("pause");
	return 0;
}