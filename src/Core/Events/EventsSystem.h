#ifndef EVENTSSYSTEM_H
#define EVENTSSYSTEM_H

#include <iostream>

enum EditorEventsType {

	START			 = 0,
	STARTAPPLICATION = 1,
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