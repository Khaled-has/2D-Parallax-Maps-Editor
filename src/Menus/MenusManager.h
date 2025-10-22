#ifndef MENUSMANAGER_H
#define MENUSMANAGER_H

enum MENUSSTATES {

	STARTMENU = 0,
	HI = 1,

};


class MenusManager 
{

public:

	// Static
	inline static MENUSSTATES menuNow = STARTMENU;


	MenusManager();

	/* Functions */
	void Update();


private:

	




	void Init();
};


#endif 

