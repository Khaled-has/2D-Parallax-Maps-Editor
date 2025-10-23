#ifndef STARTMENU_H
#define STARTMENU_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "imgui.h"

#include "nlohmann/json.hpp"


class StartMenu
{

public:



	// Public Functions
	void Update();
	void Renderer();


	// Constructor & Destructor
	StartMenu();
	~StartMenu();

private:

	
	nlohmann::json jsonFillData;

	std::vector<std::pair<std::string, int>> projectsInfos;


	// Functions
	void UpdateEditorProjectFill();
	void ReadEditorProjectsFill();


	// Init
	void Init();


};

#endif 
