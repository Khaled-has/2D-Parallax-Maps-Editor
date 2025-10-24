#ifndef MENUSMANAGER_H
#define MENUSMANAGER_H

#include "StartMenu.h"

class MenusManager 
{

public:


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

