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
		if (StartMenu_.Update()) runningMenu = STARTAPPLICATION;
	}

}

void MenusManager::Renderer()
{

	if (runningMenu == STARTMENU)
	{
		StartMenu_.Renderer();
	}

}

