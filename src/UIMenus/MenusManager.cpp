#include "HPP/MenusManager.h"


MenusManager::MenusManager()
{
	Init();
}

void MenusManager::Init()
{

}

void MenusManager::Update()
{

	if (runningMenu == STARTMENU)
	{
		StartMenu_.Update();
	}

}

void MenusManager::Renderer()
{

	if (runningMenu == STARTMENU)
	{
		StartMenu_.Renderer();
	}

}

