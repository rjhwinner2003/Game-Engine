#pragma once
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL/gl.h>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <cmath>

#ifndef M_PI    //if the pi is not defined in the cmath header file
#define M_PI 3.1415926535   //define it
#endif

class CameraEngine
{
public:
	CameraEngine();
	~CameraEngine();
	void lockCamera();
	void moveCamera(float, float);
	void moveCameraUp(float, float);
	void Control(SDL_Window *window, float movevel, float mousevel, bool mi);
	void UpdateCamera();

private:
	float camX = 0.0, camY = 0.0, camZ = 5.0;   //current position of the camera
	float camYaw = 0.0;   //camera rotation in Y axis
	float camPitch = 0.0; //camera rotation in X axis

};

