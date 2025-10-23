#include "HPP/StartMenu.h"

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
		projectsInfos.push_back(ProjectData(dataProjects["name"], dataProjects["path"]));
	}


}

void StartMenu::StartUI()
{

	ImGui::Begin("None", nullptr, flags);
	//Create Project Button
	if (ImGui::Button("Create New Project", ImVec2(215, 55))) {
		uiState = CREATE;
	}
	if (ImGui::Button("Open Project", ImVec2(215, 55))) {

	}
	ImGui::End();

	ImGui::Begin("Projects", nullptr, flags);

	//Project Render Button
	for (int i = 0; i < projectsInfos.size(); i++) {
		if (ImGui::Button(projectsInfos.at(i).name.c_str(), ImVec2(205, 40))) {

			openProject.path = projectsInfos.at(i).path;

		}
	}



	ImGui::End();

}

void StartMenu::CreateUI()
{
}

void StartMenu::Init()
{

	ReadEditorProjectsFill();

}

void StartMenu::Update()
{

	if (uiState == START)
	{
		StartUI();
	}

}

void StartMenu::Renderer()
{
}

