#pragma once

class CCamera
{
public:
	CCamera(int width, int height, float fov);
	int getWidth();
	int getHeight();
	float getFov();
	float getFocale();

private:
	int camWidth;
	int camHeight;
	float camFov;
	float camFocale;
};