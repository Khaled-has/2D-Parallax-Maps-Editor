#include "StartMenu.h"

StartMenu::StartMenu()
{
	Init();
}

StartMenu::~StartMenu()
{

}

void StartMenu::UpdateEditorProjectFill()
{



}

void StartMenu::ReadEditorProjectsFill()
{

	// Read fill
	std::fstream fill("Assets/Data/ED.json");

	fill >> jsonFillData;

	int nProjects = jsonFillData["nProjects"];
	auto& dataProjects = jsonFillData["pProjects"];

	for (int i = 0; i < nProjects; i++)
	{
		projectsInfos.emplace_back(dataProjects["name"], i);
	}


}

void StartMenu::Init()
{

	ReadEditorProjectsFill();

}

void StartMenu::Update()
{
}

void StartMenu::Renderer()
{
}

