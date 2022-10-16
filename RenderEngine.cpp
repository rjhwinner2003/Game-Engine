#include "RenderEngine.h"


RenderEngine::RenderEngine()
{
}

void RenderEngine::prepare()
{
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 640.0 / 480.0, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	cube = obj.load("test.obj");  //load it
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//float col[] = { 1.0,0.0,0.0,0.0 };
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, col);
}

void RenderEngine::render(SDL_Window *window, int WinWidth, int WinHeight)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	float pos[] = { -1.0,1.0,-2.0,1.0 };
	camera.Control(window, 0.2, 0.2, true);   //calculate the position, and rotate the camera
	camera.UpdateCamera(); //move the camera to the new location

	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glTranslatef(0.0, 0.0, -10.0);
	glCallList(cube);   //and display it
}

void RenderEngine::cleanUp()
{
}


RenderEngine::~RenderEngine()
{
}
