#include "CameraEngine.h"



CameraEngine::CameraEngine()
{
}


CameraEngine::~CameraEngine()
{
}



void CameraEngine::lockCamera()
{
	//set campitch between -90 and 90 and set camyaw between 0 and 360 degrees
	if (camPitch > 90)
		camPitch = 90;
	if (camPitch < -90)
		camPitch = -90;
	if (camYaw < 0.0)
		camYaw += 360.0;
	if (camYaw > 360.0)
		camYaw -= 360;
}

void CameraEngine::moveCamera(float dist, float dir)
{
	float rad = (camYaw + dir)*M_PI / 180.0;  //convert the degrees into radians
	camX -= sin(rad)*dist;    //calculate the new coorinate, if you don't understand, draw a right triangle with the datas, you have
	camZ -= cos(rad)*dist;    //and try to calculate the new coorinate with trigonometric functions, that should help
}

void CameraEngine::moveCameraUp(float dist, float dir)
{
	//the the same, only this time we calculate the y coorinate
	float rad = (camPitch + dir)*M_PI / 180.0;
	camY += sin(rad)*dist;
}

void CameraEngine::Control(SDL_Window *window, float movevel, float mousevel, bool mi)  //move and mouse sensitivity, and is the mouse inside the window?
{
	if (mi)  //if the mouse is in the screen
	{
		int MidX = 320;   //middle of the screen
		int MidY = 240;
		SDL_ShowCursor(SDL_DISABLE);    //we don't show the cursor
		int tmpx, tmpy;
		SDL_GetMouseState(&tmpx, &tmpy); //get the current position of the cursor
		camYaw += mousevel * (MidX - tmpx);   //get the rotation, for example, if the mouse current position is 315, than 5*0.2, this is for Y
		camPitch += mousevel * (MidY - tmpy); //this is for X
		lockCamera();
		SDL_WarpMouseInWindow(window, MidX, MidY);   //move back the cursor to the center of the screen
		const Uint8 *state = SDL_GetKeyboardState(NULL);
		if (state[SDL_SCANCODE_W])
		{
			if (camPitch != 90 && camPitch != -90)   //if we are facing directly up or down, we don't go forward, it will be commented out, when there will be gravity
				moveCamera(movevel, 0.0);    //move forward
			moveCameraUp(movevel, 0.0);  //move up/down
		}
		else if (state[SDL_SCANCODE_S])
		{
			//same, just we use 180 degrees, so we move at the different direction (move back)
			if (camPitch != 90 && camPitch != -90)
				moveCamera(movevel, 180.0);
			moveCameraUp(movevel, 180.0);
		}
		if (state[SDL_SCANCODE_A])   //move left
			moveCamera(movevel, 90.0);
		else if (state[SDL_SCANCODE_D])  //move right
			moveCamera(movevel, 270);
	}
	glRotatef(-camPitch, 1.0, 0.0, 0.0);   //rotate the camera (more precisly move everything in the opposit direction)
	glRotatef(-camYaw, 0.0, 1.0, 0.0);
}

void CameraEngine::UpdateCamera()
{
	glTranslatef(-camX, -camY, -camZ);    //move the camera
}