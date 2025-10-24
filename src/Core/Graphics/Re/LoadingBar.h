#ifndef LOADINGBAR_H
#define LOADINGBAR_H

#include <glad/glad.h>

#include "Events/EventsSystem.h"

#include "GL/Shader.h"

class LoadingBar
{

public:



	LoadingBar();
	~LoadingBar();

	void Renderer();

private:
	Shader sh{ (PRO_ASSETS_PATH + "/GLSL/Static/gl_LoadingBar.vert").c_str(), (PRO_ASSETS_PATH + "/GLSL/Static/gl_LoadingBar.frag").c_str()};


};

#endif