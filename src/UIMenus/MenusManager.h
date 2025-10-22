#ifndef MENUSMANAGER_H
#define MENUSMANAGER_H

enum UIMenusState {

	STARTMENU = 0,
	HI = 1,

};


class MenusManager 
{

public:

	// Static
	inline static UIMenusState menuNow = STARTMENU;


	MenusManager();

	/* Public Functions */
	void Update();
	void Renderer();


private:

	




	void Init();
};


#endif 

