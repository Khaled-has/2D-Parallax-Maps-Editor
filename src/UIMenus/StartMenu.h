#ifndef STARTMENU_H
#define STARTMENU_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <ShObjIdl_core.h>
#include <direct.h>

#include "imgui.h"

#include "nlohmann/json.hpp"

#include "../Core/Events/EventsSystem.h"


class StartMenu
{

public:

	// Public Functions
	bool Update();
	void Renderer();


	// Constructor & Destructor
	StartMenu();
	~StartMenu();

private:

	ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
	
	nlohmann::json jsonFillData;


	struct ProjectData {
		std::string name; std::string path; 

		ProjectData(std::string name, std::string path)
		{
			this->name = name; this->path = path;
		}
	};
	std::vector<ProjectData> projectsInfos;



	enum UIState {
		START			 = 0,
		CREATE			 = 1,
		STARTAPPLICATION = 2,
	};
	UIState uiState = START;

	// Functions
	void UpdateEditorProjectFill(std::string name, std::string path);
	void ReadEditorProjectsFill();

	void StartUI();
	void CreateUI();


	void CreatePlatformFiles(std::string path, std::string name);
	std::string OpenSystemWindow();

	// Init
	void Init();


};

#endif 
