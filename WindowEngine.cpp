#include "WindowEngine.h"
#include<assert.h>


WindowEngine::WindowEngine()
{
	WindowFlags = SDL_WINDOW_OPENGL;
	Window = SDL_CreateWindow("Engine", 0, 0, WinWidth, WinHeight, WindowFlags);

	Context = SDL_GL_CreateContext(Window);



	Running = 1;
	FullScreen = 0;
}

void WindowEngine::manageWindow()
{
	assert(Window);
	SDL_Event Event;
	while (SDL_PollEvent(&Event))
	{
		if (Event.type == SDL_KEYDOWN)
		{
			switch (Event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				Running = 0;
				break;
			case 'f':
				FullScreen = !FullScreen;
				if (FullScreen)
				{
					SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
				}
				else
				{
					SDL_SetWindowFullscreen(Window, WindowFlags);
				}
				break;
			default:
				break;
			}
		}
		else if (Event.type == SDL_QUIT)
		{
			Running = 0;
		}
	}

}


WindowEngine::~WindowEngine()
{
}
