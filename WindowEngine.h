#pragma once
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>

typedef int32_t i32;
typedef uint32_t u32;
typedef int32_t b32;

#define WinWidth 800
#define WinHeight 600

class WindowEngine
{
public:
	WindowEngine();

	void manageWindow();
	~WindowEngine();

	b32 Running;
	b32 FullScreen;

	SDL_Window *Window;

private:
	u32 WindowFlags;
	SDL_GLContext Context;
};

