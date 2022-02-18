#include "Ray.h"
#include "CSphere.h"

Ray::Ray()
{
	m_origin = new Vector3();
	m_direction = new Vector3();
}

Ray::Ray(Vector3* origin, Vector3* direction)
{
	m_origin = origin;
	m_direction = direction;
}

bool Ray::intersection(CSphere* s)
{
	float X0 = m_origin->getX() - s->getCoord().getX();
	float Y0 = m_origin->getY() - s->getCoord().getY();
	float Z0 = m_origin->getZ() - s->getCoord().getZ();

	float dx = m_direction->getX();
	float dy = m_direction->getY();
	float dz = m_direction->getZ();

	float t0 = (X0 * X0 + Y0 * Y0 + Z0 * Z0) - s->getRayon();
	float t1 = 2 * (X0 * dx + Y0 * dy + Z0 * dz);
	float t2 = dx * dx + dy * dy + dz * dz;

	float discriminant = t1 * t1 - 4.0f * (t2 * t0);

	if (discriminant == 0)
	{
		return true;
	}
	else if(discriminant > 0)
	{
		return true;
	}
	else {
		return false;
	}
}

Vector3 *Ray::getDirection()
{
	return m_direction;
}

Vector3 *Ray::getOrigin()
{
	return m_origin;
}