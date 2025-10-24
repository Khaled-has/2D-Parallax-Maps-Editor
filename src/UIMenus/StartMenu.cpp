#include "StartMenu.h"

StartMenu::StartMenu()
{
	Init();
}

StartMenu::~StartMenu()
{

}

void StartMenu::UpdateEditorProjectFill(std::string name, std::string path)
{
	
	projectsInfos.push_back(ProjectData(name, path));

	std::ifstream in("Assets/Data/ED.json");
	if (in.is_open()) {
		in >> jsonFillData;
	}

	nlohmann::json newProj = {
		{"name", name.c_str()},
		{"path", path.c_str()}
	};

	jsonFillData["pProjects"].push_back(newProj);
	int nump = jsonFillData["nProjects"];
	nump++;
	jsonFillData["nProjects"] = nump;

	std::ofstream out("Assets/Data/ED.json");
	out << jsonFillData.dump(4);

	in.close();
	out.close();

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
		projectsInfos.push_back(ProjectData(dataProjects[i]["name"], dataProjects[i]["path"]));
		std::cout << projectsInfos.at(i).name << " | " << projectsInfos.at(i).path << std::endl;
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
		if (ImGui::Button(projectsInfos.at(i).name.c_str(), ImVec2(248, 55))) {

			
			uiState = STARTAPPLICATION;

			// Send project data to Editor events system
			EventsSystem::runningProjectInfo.name = projectsInfos.at(i).name;
			EventsSystem::runningProjectInfo.path = projectsInfos.at(i).path;

		}
	}



	ImGui::End();

}

void StartMenu::CreateUI()
{

	static char text[256] = "";
	static char textPath[256] = "";

	static std::string pathProject = "";

	ImGui::Begin("None_", nullptr, flags);

	ImGui::InputText("Enter Project Name", text, IM_ARRAYSIZE(text));

	static bool run = false;
	if (ImGui::Button("Open File")) {
		pathProject = OpenSystemWindow();
	}
	ImGui::SameLine();
	strncpy_s(textPath, sizeof(textPath), pathProject.c_str(), _TRUNCATE);
	ImGui::InputText("Enter Project Path", textPath, IM_ARRAYSIZE(textPath));


	ImGui::End();

	ImGui::Begin("None__", nullptr, flags);
	if (ImGui::Button("Create", ImVec2(180, 40)) && text[0] > 0 && textPath[0] > 0) {
		std::string result = text;

		CreatePlatformFiles(pathProject, result);
		
		// Send project data to Editor events system
		EventsSystem::runningProjectInfo.name = pathProject + "/" + result;
		EventsSystem::runningProjectInfo.path = result;

		uiState = STARTAPPLICATION;

		UpdateEditorProjectFill(result, pathProject + "/" + result);

	}
	ImGui::SameLine();
	if (ImGui::Button("Cancel", ImVec2(180, 40))) {
		uiState = START;
	}

	ImGui::End();

}

void StartMenu::CreatePlatformFiles(std::string path, std::string name)
{

	_mkdir(((path + "/" + name).c_str()));

	//Create File MapsData
	_mkdir(((path + "/" + name + "/MapsData").c_str()));
	//Create File Assets
	_mkdir(((path + "/" + name + "/Assets").c_str()));

	//Create Json File & Wrait Them
	std::ofstream cr((path + "/" + name + "\\proj.json").c_str());
	cr << "{";
	cr << "\n";
	cr << "}";
	cr.close();


	std::ofstream ofs;
	ofs.open((path + "/" + name + "\\proj.json").c_str(), std::ios::trunc);

	nlohmann::json j;
	j["nMaps"].is_number_integer();
	j["nMaps"] = 0;

	j["namesMaps"].is_array();

	if (ofs.is_open()) {
		ofs << j.dump(4);
		ofs.close();
	}


}

std::string StartMenu::OpenSystemWindow()
{

	// Open Windows Window For Select Path Folder For Save Maps_Data

	CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	IFileDialog* dlg = nullptr;

	if (SUCCEEDED(CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dlg)))) {
		DWORD options;
		dlg->GetOptions(&options);
		dlg->SetOptions(options | FOS_PICKFOLDERS);

		if (SUCCEEDED(dlg->Show(NULL))) {
			IShellItem* item;

			if (SUCCEEDED(dlg->GetResult(&item))) {

				PWSTR path;

				if (SUCCEEDED(item->GetDisplayName(SIGDN_FILESYSPATH, &path))) {

					char buffer[MAX_PATH];

					WideCharToMultiByte(CP_UTF8, 0, path, -1, buffer, MAX_PATH, nullptr, nullptr);

					CoTaskMemFree(path);
					item->Release();
					dlg->Release();
					CoUninitialize();

					return std::string(buffer);
				}

				item->Release();
			}
		}

		dlg->Release();
	}
	CoUninitialize();

	return "";
}

void StartMenu::Init()
{

	ReadEditorProjectsFill();

}

bool StartMenu::Update()
{

	// Start
	if (uiState == START)
	{
		StartUI();
	}
	// Create projects
	else if (uiState == CREATE)
	{
		CreateUI();
	}

	// Start application
	if (uiState == STARTAPPLICATION)
		return true;
	else
		return false;

}

void StartMenu::Renderer()
{
}

