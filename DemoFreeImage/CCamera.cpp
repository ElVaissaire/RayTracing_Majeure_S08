#include "CCamera.h"
#include <math.h>

#define PI 3.14159
#define DEG_RAD PI/180.f

CCamera::CCamera(int width, int height, float fov)
{
	camWidth = width;
	camHeight = height;
	camFov = fov;
	camFocale = width / (2.0f * tan(DEG_RAD) * camFov / 2.0f);
}

int CCamera::getWidth()
{
	return camWidth;
}

int CCamera::getHeight()
{
	return camHeight;
}

float CCamera::getFov()
{
	return camFov;
}

float CCamera::getFocale()
{
	return camFocale;
}