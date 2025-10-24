#include "MenusManager.h"


MenusManager::MenusManager()
{
	Init();
}

void MenusManager::Init()
{

}

void MenusManager::Update()
{

	if (EventsSystem::applicationState == START)
	{
		if (StartMenu_.Update()) EventsSystem::applicationState = STARTAPPLICATION;
	}

}

void MenusManager::Renderer()
{

	if (EventsSystem::applicationState == START)
	{
		StartMenu_.Renderer();
	}

}

