#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>

#include <glad/glad.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_dialog.h>

#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_opengl3.h>

class Window {
public:
	Window();
	~Window();

	void SwapWindow();
	void GetWindowSize(int* w, int* h);
	void SetSize(int w, int h);
	void SetWindowPosCenterd();
	void NoFullScreen();

private:
	SDL_Window* win;
	SDL_GLContext sdl_context;


};

#endif