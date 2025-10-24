#ifndef EVENTSSYSTEM_H
#define EVENTSSYSTEM_H

#include <iostream>


// Get Device Assets Path From CMAKE
#ifdef ASSETS_PATH
inline static std::string PRO_ASSETS_PATH = ASSETS_PATH;
#endif



enum EditorEventsType {

	START			 = 0,
	STARTEDITOR		 = 1,
	EDITORRUNNING    = 2

};

struct RunningProjectInfo
{
	std::string path;
	std::string name;
};

class EventsSystem
{

public:

	// Editor events
	inline static EditorEventsType applicationState = START;
	inline static RunningProjectInfo runningProjectInfo;

};

#endif