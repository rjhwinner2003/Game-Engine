
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>

#include "ModelEngine.h"
#include "RenderEngine.h"
#include "FXEngine.h"
#include "WindowEngine.h"



typedef int32_t i32;
typedef uint32_t u32;
typedef int32_t b32;




WindowEngine windEngine;
RenderEngine rendEngine;


int main(int ArgCount, char **Args)
{
	windEngine = WindowEngine();

	rendEngine.prepare();

	while (windEngine.Running)
	{
		windEngine.manageWindow();
		rendEngine.render(windEngine.Window, WinWidth, WinHeight);

		SDL_GL_SwapWindow(windEngine.Window);
	}
	return 0;
}