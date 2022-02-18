#pragma once

class CMaterial
{
public:
	CMaterial();
	CMaterial(int red, int green, int blue, float ka, float kd, float ks, float ke);

private:
	int m_red;
	int m_green;
	int m_blue;
	float m_ka;
	float m_kd;
	float m_ks;
	float m_ke;
};