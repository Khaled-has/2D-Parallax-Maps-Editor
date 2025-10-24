#include "Window.h"

#include "Events/EventsSystem.h"


Window::Window()
{

	//Set Attribute SDL + OpenGL 460
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	//Create Window & Context & Glad Loader
	win = SDL_CreateWindow(
		"Project 0.0.2",
		1250, 660,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	sdl_context = SDL_GL_CreateContext(win);
	SDL_GL_MakeCurrent(win, sdl_context);

	gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);


	// Init ImGui IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplSDL3_InitForOpenGL(win, sdl_context);
	ImGui_ImplOpenGL3_Init("#version 460 core");

	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |=
		ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

	(void)io;

	ImGui::StyleColorsDark();
	ImGui::GetStyle().Colors[ImGuiCol_WindowBg] = ImVec4(0.2f, 0.2f, 0.2f, 1.0f);
	ImGui::GetStyle().Colors[ImGuiCol_Button] = ImVec4(0.46f, 0.46f, 0.46f, 0.68f);
	ImGui::GetStyle().Colors[ImGuiCol_TitleBgActive] = ImVec4(0.09f, 0.09f, 0.09f, 1.0f);
	ImGui::GetStyle().Colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.09f, 0.09f, 1.0f);
	ImGui::GetStyle().WindowRounding = 0.f;
	ImGui::GetStyle().FrameRounding = 10.f;
	ImGui::GetStyle().FontScaleDpi = 1.260f;
	ImGui::GetStyle().FrameBorderSize = 1.f;
	ImGui::GetStyle().Colors[ImGuiCol_ButtonHovered] = ImVec4(0.6f, 0.6f, 0.6f, 1.f);
	ImGui::GetStyle().Colors[ImGuiCol_ButtonActive] = ImVec4(0.9f, 0.9f, 0.9f, 1.f);

	io.Fonts->AddFontFromFileTTF((PRO_ASSETS_PATH + "/Fonts/Uni Sans Heavy.otf").c_str(), 13.0f);

}

Window::~Window()
{

	SDL_GL_DestroyContext(sdl_context);
	SDL_DestroyWindow(win);
	SDL_Quit();

}

void Window::SwapWindow()
{

	// Update Window Frame
	SDL_GL_SwapWindow(win);

}

void Window::GetWindowSize(int* w, int* h)
{

	SDL_GetWindowSize(win, w, h);

}

void Window::SetSize(int w, int h)
{
	
	SDL_SetWindowSize(win, w, h);

}

void Window::SetWindowPosCenterd()
{
	SDL_SetWindowPosition(win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}

void Window::NoFullScreen()
{
	SDL_SetWindowFullscreen(win, 0);
}
