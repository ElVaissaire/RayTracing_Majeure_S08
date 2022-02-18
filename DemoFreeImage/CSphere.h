#pragma once
#include "Vector3.h"
#include "CMaterial.h"
#include <math.h>

class CSphere
{
public:
	CSphere();
	CSphere(Vector3 *coord, float rayon);
	void setMaterial(CMaterial *m);
	Vector3 getCoord();
	float getRayon();

private:
	Vector3* m_coord;
	float m_rayon;
	CMaterial *m_m;
};