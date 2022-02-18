#include "CLight.h"

CLight::CLight()
{
	m_pos = new Vector3();
	m_red = 255;
	m_green = 255;
	m_blue = 255;
}

CLight::CLight(Vector3* position, int red, int green, int blue)
{
	m_pos = position;
	m_red = red;
	m_green = green;
	m_blue = blue;
}