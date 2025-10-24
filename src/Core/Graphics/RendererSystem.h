#ifndef RENDERERSYSTEM_H
#define RENDERERSYSTEM_H

#include "Re/LoadingBar.h"

class RendererSystem
{

public:




	// Public Functions
	void Renderer();


	// Constructor & Destructor
	RendererSystem();
	~RendererSystem();


private:

	// Rendering Components
	LoadingBar loadingBar;

	// Init 
	void InitRenderSystem();

};

#endif