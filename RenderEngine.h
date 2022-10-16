#pragma once
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include "ModelEngine.h"
#include "FXEngine.h"
#include "CameraEngine.h"

class RenderEngine
{
public:
	RenderEngine();

	void prepare();
	void render(SDL_Window *window, int WinWidth, int WinHeight);
	void cleanUp();

	~RenderEngine();

private:
	int cube;
	objloader obj;  //create an instance of the objloader
	CameraEngine camera;
	
	 	
};

