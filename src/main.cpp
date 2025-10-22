#include <iostream>

#include "Window.h"

#include "UIMenus/MenusManager.h"

#include <glm/glm.hpp>

struct FrameRatLimit {
private:
	int frame_delay = 0;
	Uint32 frameStart = 0;
	int frameTime = 0;

public:
	FrameRatLimit() {

	}

	void SetFrameLimet(int frame) {
		frame_delay = 1000 / frame;
	}

	void StartPrgrame() {
		frameStart = SDL_GetTicks();
	}

	void EndPrograme() {
		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frame_delay) {
			SDL_Delay(frame_delay - frameTime);
		}

	}

	void Set_VSYNC(bool done) {
		SDL_GL_SetSwapInterval(done);
	}

};

void UpdateGUI() {

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

	ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(ImVec2(viewport->Pos.x - 10.f, viewport->Pos.y + 15.f));
	ImGui::SetNextWindowSize(ImVec2(viewport->Size.x + 20.f, viewport->Size.y + 15.f));
	ImGui::SetNextWindowViewport(viewport->ID);

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus |
		ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.f);

	ImGui::Begin("MainDockSpace", nullptr, window_flags);
	ImGui::PopStyleVar(2);

	ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
	ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f),
		ImGuiDockNodeFlags_PassthruCentralNode | ImGuiDockNodeFlags_NoDockingInCentralNode);
	ImGui::End();

}
void GL_Clear(Window* win) {

	ImGui::Render();
	int w, h;
	win->GetWindowSize(&w, &h);
	glViewport(0, 0, w, h);
	glClearColor(0.1f, 0.1f, 0.1f, 1);
	glClear(GL_COLOR_BUFFER_BIT);

}

int main(int argc, char* argv[]) {

	//SDL Init
	SDL_Init(SDL_INIT_VIDEO);

	// Window Init
	Window win;



	// ---- Init
	MenusManager MenusManager_;




	// Loop
	bool run = true;
	SDL_Event ev;


	FrameRatLimit updateFrames;
	updateFrames.SetFrameLimet(50);

	FrameRatLimit rendererFrames;
	rendererFrames.SetFrameLimet(60);

	while (run) {

		updateFrames.StartPrgrame();		   // Start update loop

		// --------------------------------------------------------------------------------------------------
		// -----------------------------------------(   PollEvents   )------------------------------------------
		// --------------------------------------------------------------------------------------------------

		{
			while (SDL_PollEvent(&ev)) {
				if (ev.type == SDL_EVENT_QUIT)
					run = false;

				ImGui_ImplSDL3_ProcessEvent(&ev);
			}
		}

		// --------------------------------------------------------------------------------------------------
		// -------------------------------------------(   Update   )-------------------------------------------
		// --------------------------------------------------------------------------------------------------

		// ImGui Update
		UpdateGUI();




		MenusManager_.Update();


		updateFrames.EndPrograme();			 // End update loop 





		// --------------------------------------------------------------------------------------------------
		// -------------------------------------------(   Renderer   )-------------------------------------------
		// --------------------------------------------------------------------------------------------------

		rendererFrames.StartPrgrame();		 // Start renderer loop

		GL_Clear(&win);






		// ImGui Render Last
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());




		win.SwapWindow();

		rendererFrames.EndPrograme();		// End renderer loop
		
	}

	

	return 0;
}