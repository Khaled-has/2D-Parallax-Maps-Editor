#ifndef MENUSMANAGER_H
#define MENUSMANAGER_H

#include "StartMenu.h"


enum UIMenusState {

	STARTMENU		 = 0,
	STARTAPPLICATION = 1

};


class MenusManager 
{

public:


	// Static variables
	inline static UIMenusState runningMenu = STARTMENU;


	// Constructor
	MenusManager();

	/* Public Functions */
	void Update();
	void Renderer();


private:

	// Menus
	StartMenu StartMenu_;
	




	void Init();
};


#endif 

