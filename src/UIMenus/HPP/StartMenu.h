#ifndef STARTMENU_H
#define STARTMENU_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "imgui.h"

#include "nlohmann/json.hpp"


struct OpenProject
{

	std::string path = "NONE";

	// Settings


};


class StartMenu
{

public:

	inline static OpenProject openProject;


	// Public Functions
	void Update();
	void Renderer();


	// Constructor & Destructor
	StartMenu();
	~StartMenu();

private:

	ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse;
	
	nlohmann::json jsonFillData;


	struct ProjectData { std::string name; std::string path; };
	std::vector<ProjectData> projectsInfos;



	enum UIState {
		START	= 0,
		CREATE  = 1,
	};
	UIState uiState = START;

	// Functions
	void UpdateEditorProjectFill();
	void ReadEditorProjectsFill();

	void StartUI();
	void CreateUI();


	// Init
	void Init();


};

#endif 
