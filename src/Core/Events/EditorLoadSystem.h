#ifndef EDITORLOADSYSTEM_H
#define EDITORLOADSYSTEM_H

#include "EventsSystem.h"

class EditorLoadSystem
{

public:

	inline static float loadProgress = 0.f;

	void Update()
	{

		if (EventsSystem::applicationState == STARTEDITOR)
		{

			if (loadProgress >= 1.f)
			{
				EventsSystem::applicationState = EDITORRUNNING;
			}

		}
		else if (loadProgress != 0.f)
		{
			loadProgress = 0.f;
		}


	}

};

#endif