#include "CMaterial.h"

CMaterial::CMaterial()
{
	m_red = 255;
	m_green = 255;
	m_blue = 255;
	m_ka = 0.0f;
	m_kd = 0.0f;
	m_ks = 0.0f;
	m_ke = 0.0f;
}

CMaterial::CMaterial(int red, int green, int blue, float ka, float kd, float ks, float ke)
{
	m_red = red;
	m_green = green;
	m_blue = blue;
	m_ka = ka;
	m_kd = kd;
	m_ks = ks;
	m_ke = ke;
}