#pragma once
#include "Vector3.h"

class CLight
{
public:
	CLight();
	CLight(Vector3 *position, int red, int green, int blue);
	Vector3 *getCoord();
	
private:
	Vector3* m_pos;
	int m_red;
	int m_green;
	int m_blue;
};