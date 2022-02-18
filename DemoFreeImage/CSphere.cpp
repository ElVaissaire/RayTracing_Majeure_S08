#include "CSphere.h"


CSphere::CSphere() 
{
	m_coord = new Vector3();
	m_rayon = 0.0f;
}

CSphere::CSphere(Vector3* coord, float rayon)
{
	m_coord = coord;
	m_rayon = rayon;
}

Vector3 CSphere::getCoord()
{
	return *m_coord;
}

float CSphere::getRayon()
{
	return m_rayon;
}